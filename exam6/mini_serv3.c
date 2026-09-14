/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <alamjada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:25:20 by salman            #+#    #+#             */
/*   Updated: 2026/09/08 22:36:08 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_client {
	int fd;
	int id;
	char *buff_send;
	char *buff_read;
	struct s_client *next;
} t_client;

t_client *g_clients = NULL;
int g_max_fd = 0;
int g_next_id = 0;

void err(char *msg) {
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

int create_socket(int port) {
	struct sockaddr_in saddr;
	int fd = socket(AF_INET, SOCK_STREAM, 0);

	if (fd == -1)
		err("Fatal error");

	bzero(&saddr, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	if (bind(fd, (struct sockaddr *)&saddr, sizeof(saddr)) == -1) {
		close(fd);
		err("Fatal error");
	}

	if (listen(fd, 1000) == -1) {
		close(fd);
		err("Fatal error");
	}
	return fd;
}

char *ft_strjoin(char *buf, char *add) {
	int i = 0;
	char *dest;

	if (buf)
		i = strlen(buf);
	dest = malloc(i + strlen(add) + 1);
	if (!dest)
		err("Fatal error");
	dest[0] = '\0';
	if (buf)
		strcpy(dest, buf);
	strcat(dest, add);
	free(buf);
	return dest;
}

t_client *add_client(int fd) {
	t_client *client = malloc(sizeof(t_client));
	if (!client)
		err("Fatal error");
	client->fd = fd;
	client->id = g_next_id++;
	client->buff_send = NULL;
	client->buff_read = NULL;
	client->next = g_clients;
	g_clients = client;
	return client;
}

void remove_client (t_client *target) {
	t_client *curr  = g_clients;
	t_client *prev = NULL;

	while (curr) {
		if (curr == target) {
			if (prev)
				prev->next = curr->next;
			else
				g_clients = curr->next;
			close(curr->fd);
			free(curr->buff_send);
			free(curr->buff_read);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void send_to_all(t_client *except, char *msg) {
	t_client *curr = g_clients;
	while (curr) {
		if (curr != except)
			curr->buff_send = ft_strjoin(curr->buff_send, msg);
		curr = curr->next;
	}
}

int extract_message(char **buf, char **msg) {
	char *b;
	char *newb;

	b = *buf;
	*msg = NULL;
	if (!b)
		return 0;

	int i = 0;
	while (b[i]) {
		if (b[i] == '\n') {
			newb = calloc(1, strlen(b + i + 1) + 1);
			if (!newb)
				err("Fatal error");
			strcpy(newb, b + i + 1);

			b[i + 1] = '\0';
			*msg = b;
			*buf = newb;
			return 1;
		}
		i++;
	}
	return 0;
}

int main(int ac, char **av) {
	char msg[64];
	char buf[4096];

	if (ac != 2)
		err("Wrong number of arguments");

	int server_fd = create_socket(atoi(av[1]));

	while (1) {
		fd_set read_fds;
		fd_set write_fds;

		FD_ZERO(&read_fds);
		FD_ZERO(&write_fds);
		FD_SET(server_fd, &read_fds);
		g_max_fd = server_fd;

		t_client *curr = g_clients;
		while (curr) {
			FD_SET(curr->fd, &read_fds);
			if (curr->buff_send)
				FD_SET(curr->fd, &write_fds);
			if (curr->fd > g_max_fd)
				g_max_fd = curr->fd;
			curr = curr->next;
		}

		if (select(g_max_fd + 1, &read_fds, &write_fds, NULL, NULL) == -1)
			continue;

		if (FD_ISSET(server_fd, &read_fds)) {
			int new_fd = accept(server_fd, NULL, NULL);

			if (new_fd >= FD_SETSIZE)
				close(new_fd);
			else if (new_fd >= 0) {
				t_client *new_client = add_client(new_fd);
				sprintf(msg, "server: client %d just arrived\n", new_client->id);
				send_to_all(new_client, msg);
			}
		}

		curr = g_clients;
		while (curr) {
			t_client *next = curr->next;
			int disconnect = 0;

			// read
			if (FD_ISSET(curr->fd, &read_fds)) {
				int ret = recv(curr->fd, buf, sizeof(buf) - 1, 0);
				if (ret <= 0) {
					sprintf(msg, "server: client %d just left\n", curr->id);
					send_to_all(curr, msg);
					remove_client(curr);
					disconnect = 1;
				} else {
					buf[ret] = '\0';
					curr->buff_read = ft_strjoin(curr->buff_read, buf);

					char *line;
					while (extract_message(&curr->buff_read, &line)) {
						sprintf(msg, "client %d: ", curr->id);

						t_client *dest = g_clients;
						while (dest) {
							if (dest != curr) {
								dest->buff_send = ft_strjoin(dest->buff_send, msg);
								dest->buff_send = ft_strjoin(dest->buff_send, line);
							}
							dest = dest->next;
						}
						free(line);
					}
				}
			}

			// write
			if (!disconnect && FD_ISSET(curr->fd, &write_fds) && curr->buff_send) {
				int len = strlen(curr->buff_send);
				int ret = send(curr->fd, curr->buff_send, len, 0);
				if (ret <= 0) {
					sprintf(msg, "server: client %d just left\n", curr->id);
					send_to_all(curr, msg);
					remove_client(curr);
				} else if (ret == len) {
					free(curr->buff_send);
					curr->buff_send = NULL;
				} else {
					char *rest = calloc(1, len - ret + 1);
					if (!rest )
						err("Fatal error");
					strcpy(rest, curr->buff_send + ret);
					free(curr->buff_send);
					curr->buff_send = rest;
				}
			}
			curr = next;
		}
	}
	return 0;
}
