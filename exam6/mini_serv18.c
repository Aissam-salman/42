#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

typedef struct s_client {
	int fd;
	int id;
	char *bread;
	char *bsend;
	struct s_client *next;
} t_client;

t_client *g_clients = NULL;
int g_next_id = 0;
int g_max_fd = 0;

void err(char *msg);
int create_socket(int port);
t_client *add_client(int fd);
char *ft_strjoin(char *b, char *add);
void clean_cl(t_client *c);
void remove_client(t_client *);
void send_to(t_client *except, char *msg);
int extract_msg(char **buf, char **msg);

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

		//NEW CLI
		if (select(g_max_fd + 1, &read_fds, &write_fds, NULL, NULL) == -1)
			continue;
		if (FD_ISSET(server_fd, &read_fds)) {
			int newfd = accept(server_fd, NULL, NULL);

			if (newfd >= FD_SETSIZE)
				close(newfd);
			else if (newfd >= 0) {
				t_client *c = add_client(newfd);
				sprintf(msg, "server: client %d just arrived\n", c->id);
				send_to(c, msg);
			}
		}

		cr = g_clients;
		while (cr) {
			t_client *next = cr->next;
			int disc = 0;


			// READ
			if (FD_ISSET(cr->fd, &read_fds)) {
				int ret = recv(cr->fd, buf, sizeof(buf) - 1, 0);
				if (ret <= 0) {
					sprintf(msg, "server: client %d just left\n", cr->id);
					send_to(cr, msg);
					remove_client(cr);
					disc = 1;
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
			if (!disc && FD_ISSET(cr->fd, &write_fds) && cr->bsend) {
				int len = strlen(cr->bsend);
				int ret = send(cr->fd, cr->bsend, len, 0);

				if (ret <= 0) {
					sprintf(msg, "server: client %d just left\n", cr->id);
					send_to(cr, msg);
					remove_client(cr);
				}
				else if (ret == len) {
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
