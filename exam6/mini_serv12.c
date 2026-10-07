#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct s_client {
	int id;
	char *msg;
} t_client;

t_client clients[1024];
fd_set active_fds, read_fds, write_fds;
int max_fd = 0;
int next_id = 0;
char bread[4096];

void fatal(void);

void notify(int sender, char *msg) {
	for (int fd = 0; fd <= max_fd; fd++) {
		if (FD_ISSET(fd, &write_fds) && sender != fd)
			send(fd, msg, strlen(msg), MSG_NOSIGNAL);
	}
}
char *strjoin(char *b, char *add);
int extract_msg(char **buf, char **msg);


void accept_client(int fd) {
	int client_fd = accept(fd, NULL, NULL);
	if (client_fd < 0)
		fatal();
	if (client_fd > max_fd)
		max_fd = client_fd;
	clients[client_fd].id = next_id++;
	clients[client_fd].msg = NULL;
	FD_SET(client_fd, &active_fds);

	char buf[100];
	sprintf(buf, "server: client %d just arrived\n", clients[client_fd].id);
	notify(client_fd, buf);
}

void remove_client(int fd) {
	char buf[100];
	sprintf(buf, "server: client %d just left\n", clients[fd].id);
	notify(fd, buf);
	FD_CLR(fd, &active_fds);

	if (clients[fd].msg) {
		free(clients[fd].msg);
		clients[fd].msg = NULL;
	}
}

void send_msg(int fd) {
	int ret = recv(fd, bread, sizeof(bread) - 1, 0);
	if (ret <= 0) {
		remove_client(fd);
		return ;
	}
	bread[ret] = '\0';
	clients[fd].msg = strjoin(clients[fd].msg, bread);

	char *line = NULL;
	while (extract_msg(&clients[fd].msg, &line)) {
		char pr[50];
		sprintf(pr, "client %d: ", clients[fd].id);

		char *fm = malloc(strlen(pr) + strlen(line) + 1);
		if (!fm)
			fatal();
		strcpy(fm, pr);
		strcat(fm, line);
		notify(fd, fm);
		free(fm);
		free(line);
	}
}

int create_socket(int port);


int main(int ac, char **av) {
	if (ac != 2) {
		write(2, "Wrong number of arguments", 26);
		exit(1);
	}

	int server_fd = create_socket(atoi(av[1]));

	FD_ZERO(&active_fds);
	FD_SET(server_fd, &active_fds);
	max_fd = server_fd;

	while (1) {
		read_fds = write_fds = active_fds;

		if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max_fd; fd++) {
			if (FD_ISSET(fd, &read_fds)) {
				if (server_fd == fd)
					accept_client(server_fd);
				else
					send_msg(fd);
				break;
			}
		}
	}
	return 0;
}
