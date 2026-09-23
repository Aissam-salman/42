#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct s_client {
	int fd;
	int id;
	char *bsend;
	char *bread;
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

char *ft_strjoin(char *b, char *add) {
	int i = 0;
	char *dest;

	if (b)
		i = strlen(b);
	dest = malloc(i + strlen(add) + 1);
	if (!dest)
		err("Fatal error");
	dest[0] = '\0';
	if (b)
		strcpy(dest, b);
	strcat(dest, add);
	free(b);
	return dest;
}

t_client *add_client(int fd) {
	t_client *cl = malloc(sizeof(t_client));
	if (!cl)
		err("Fatal error");
	cl->fd = fd;
	cl->id = g_next_id++;
	cl->bsend = NULL;
	cl->bread = NULL;
	cl->next = g_clients;
	g_clients = cl;
	return cl;
}

void remove_client(t_client *t) {
	t_client *curr = g_clients;
	t_client *prev = NULL;

	while (curr) {
		if (curr == t) {
			if (prev)
				prev->next = curr->next;
			else
				g_clients = curr->next;
			close(curr->fd);
			free(curr->bsend);
			free(curr->bread);
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

void send_to_all(t_client *except, char *msg) {
	t_client *cr = g_clients;
	while (cr) {
		if (cr != except)
			cr->bsend = ft_strjoin(cr->bsend, msg);
		cr = cr->next;
	}
}

int extract_msg(char **buf, char **msg) {
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

		t_client *cr = g_clients;
		while (cr) {
			FD_SET(cr->fd, &read_fds);
			if (cr->bsend)
				FD_SET(cr->fd, &write_fds);
			if (cr->fd > g_max_fd)
				g_max_fd = cr->fd;
			cr = cr->next;
		}

		if (select(g_max_fd + 1, &read_fds, &write_fds, NULL, NULL) == -1)
			continue;

		if (FD_ISSET(server_fd, &read_fds)) {
			int new_fd = accept(server_fd, NULL, NULL);

			if (new_fd >= FD_SETSIZE)
				close(new_fd);
			else if (new_fd >= 0) {
				t_client *ncl = add_client(new_fd);
				sprintf(msg, "server: client %d just arrived\n", ncl->id);
				send_to_all(ncl, msg);
			}
		}

		cr = g_clients;
		while (cr) {
			t_client *next = cr->next;
			int disco = 0;

			//READ
			if (FD_ISSET(cr->fd, &read_fds)) {
				int ret = recv(cr->fd, buf, sizeof(buf) - 1, 0);
				if (ret <= 0) {
					sprintf(msg, "server: client %d just left\n", cr->id);
					send_to_all(cr, msg);
					remove_client(cr);
					disco = 1;
				} else {
					buf[ret] = '\0';
					cr->bread = ft_strjoin(cr->bread, buf);

					char *line;
					while (extract_msg(&cr->bread, &line)) {
						sprintf(msg, "client %d: ", cr->id);

						t_client *dest = g_clients;
						while (dest) {
							if (dest != cr) {
								dest->bsend = ft_strjoin(dest->bsend, msg);
								dest->bsend = ft_strjoin(dest->bsend, line);
							}
							dest = dest->next;
						}
						free(line);
					}
				}
			}

			//WRITE
			if (!disco && FD_ISSET(cr->fd, &write_fds) && cr->bsend) {
				int len = strlen(cr->bsend);
				int ret = send(cr->fd, cr->bsend, len, 0);
if (ret <=0) {
					sprintf(msg, "server: client %d just left\n", cr->id);
					send_to_all(cr, msg);
					remove_client(cr);
				} else if (ret == len) {
					free(cr->bsend);
					cr->bsend = NULL;
				} else {
					char *rest = calloc(1, len - ret + 1);
					if (!rest)
						err("Fatal error");
					strcpy(rest, cr->bsend + ret);
					free(cr->bsend);
					cr->bsend = rest;
				}
			}
			cr = next;
		}
	}
	return 0;
}
