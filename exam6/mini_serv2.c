/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <alamjada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:09:17 by salman            #+#    #+#             */
/*   Updated: 2026/09/07 16:08:27 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

// STRUCT & GLOBALS
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

// UTILS
size_t ft_strlen(char *str) {
	size_t i = 0;
	while (str[i])
		i++;
	return i;
}

void err(char *msg) {
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

char *ft_strjoin(char *buf, char *add) {
	int len = 0;
	char *newb;

	if (buf)
		len = ft_strlen(buf);
	newb = malloc(len + ft_strlen(add) + 1);
	if (!newb)
		err("Fatal error");
	newb[0] = '\0';
	if (buf)
		strcpy(newb, buf);
	strcat(newb, add);
	free(buf);
	return newb;
}

// CLIENT
t_client *add_client(int new_fd) {
	t_client *new_client = malloc(sizeof(t_client));

	if (!new_client)
		err("Fatal error");
	new_client->fd = new_fd;
	new_client->id = g_next_id++;
	new_client->buff_send = NULL;
	new_client->buff_read = NULL;
	new_client->next = g_clients;
	g_clients = new_client;
	return new_client;
}

void remove_client(t_client *target) {
	t_client *curr = g_clients;
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
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

// CORE

int extract_message(char **buf, char **msg) {
	char *b;
	char *newb;
	int i;

	b = *buf;
	*msg = NULL;
	if (!b)
		return 0;

	i = 0;
	while (b[i]) {
		if (b[i] == '\n') {
			newb = calloc(1, ft_strlen(b + i + 1) + 1);
			if (!newb)
				err("Fatal error");
			strcpy(newb, b + i + 1);

			b[i + 1] = '\0'; // on coupe juste après le \n
			*msg = b;		 // le message (avec son \n) part vers l'appelant
			*buf = newb;	 // le reste devient le nouveau buffer
			return 1;
		}
		i++;
	}
	return 0;
}

void send_to_all(t_client *except, char *msg) {
	t_client *curr = g_clients;
	while (curr) {
		if (curr != except)
			curr->buff_send = ft_strjoin(curr->buff_send, msg);
		curr = curr->next;
	}
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

		// new conn
		if (FD_ISSET(server_fd, &read_fds)) {
			int new_fd = accept(server_fd, NULL, NULL);

			if (new_fd >= FD_SETSIZE) {
				close(new_fd);
			} else if (new_fd >= 0) {
				t_client *new_client = add_client(new_fd);
				sprintf(msg, "server: client %d just arrived\n",
						new_client->id);
				send_to_all(new_client, msg);
			}
		}

		// read / write
		curr = g_clients;
		while (curr) {
			t_client *next = curr->next;
			int disco = 0;

			if (FD_ISSET(curr->fd, &read_fds)) {
				int ret = recv(curr->fd, buf, sizeof(buf) - 1, 0);
				if (ret <= 0) {
					sprintf(msg, "server: client %d just left\n", curr->id);
					send_to_all(curr, msg);
					remove_client(curr);
					disco = 1;
				} else {
					buf[ret] = '\0';
					curr->buff_read = ft_strjoin(curr->buff_read, buf);

					char *line;
					while (extract_message(&curr->buff_read, &line)) {
						sprintf(msg, "client %d: ", curr->id);

						t_client *dest = g_clients;
						while (dest) {
							if (dest != curr) {
								dest->buff_send =
									ft_strjoin(dest->buff_send, msg);
								dest->buff_send =
									ft_strjoin(dest->buff_send, line);
							}
							dest = dest->next;
						}
						free(line);
					}
				}
			}

			if (!disco && FD_ISSET(curr->fd, &write_fds) && curr->buff_send) {
				int len = ft_strlen(curr->buff_send);
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
					if (!rest)
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
