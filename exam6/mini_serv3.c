#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>

typedef struct s_client {
	int id;
	char *msg;
} t_client;

t_client  clients[1024];
fd_set active_fds, read_fds, write_fds;
int max_fd = 0;
int next_id = 0;
char bread[4096];

void fatal(void) {
	write(2, "Fatal error\n", 12);
	exit(1);
}

void notify(int sender_fd, char *msg) {
	for(int fd = 0; fd <= max_fd; fd++) {
		if (FD_ISSET(fd, &write_fds) && fd != sender_fd)
			send(fd, msg, strlen(msg), MSG_NOSIGNAL);
	}
}

char *ft_strjoin(char *b, char *add) {
	char *d;
	int len = 0;

	if (b)
		len = strlen(b);
	d = malloc(len + strlen(add) + 1);
	if (!d)
		fatal();
	d[0] = '\0';
	if (b)
		strcpy(d, b);
	strcat(d, add);
	free(b);
	return d;
}

int extract_msg(char **buf, char **msg) {
	char *b;
	char *newb;

	b = *buf;
	*msg = 0;
	if (!b)
		return 0;

	int i = 0;
	while (b[i]) {
		if (b[i] == '\n') {
			newb = calloc(1, strlen(b + i + 1) + 1);
			if (!newb)
				fatal();
			strcpy(newb, b + i + 1);
			*msg = b;
			(*msg)[i + 1] = 0;
			*buf = newb;
			return 1;
		}
		i++;
	}
	return 0;

}

void accept_client(int fd) {
	int client_fd = accept(fd, NULL, NULL);
	if (client_fd < 0)
		return;
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
	close(fd);
	if (clients[fd].msg) {
		free(clients[fd].msg);
		clients[fd].msg = NULL;
	}
}

void send_msg(int fd) {
	int ret = recv(fd, bread, 4000, 0);
	if (ret <= 0) {
		remove_client(fd);
		return;
	}
	bread[ret] = '\0';
	clients[fd].msg = ft_strjoin(clients[fd].msg, bread);

	char *line = NULL;
	while (extract_msg(&clients[fd].msg, &line)) {
		char prefix[50];
		sprintf(prefix, "client %d: ", clients[fd].id);

		char *fmsg = malloc(strlen(prefix) + strlen(line) + 1);
		if (!fmsg)
			fatal();

		strcpy(fmsg, prefix);
		strcat(fmsg, line);
		notify(fd, fmsg);
		free(fmsg);
		free(line);
	}
}

int create_socket(int port) {
	struct sockaddr_in saddr;
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		fatal();

	bzero(&saddr, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	if (bind(fd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
		fatal();

	if (listen(fd, 500) < 0)
		fatal();

	return fd;
}

int main(int ac, char **av) {
	if (ac != 2) {
		write(2, "Wrong number of arguments\n", 26);
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
				if (fd == server_fd)
					accept_client(server_fd);
				else
					send_msg(fd);
				break;
			}
		}
	}
	return 0;
}
