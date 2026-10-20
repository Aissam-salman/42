#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
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
int max_fd = 0, next_id = 0;
char buf_read[4096];

void fatal(void) {
	write(2, "Fatal error\n", 12);
	exit(1);
}

void notify_others(int sender_fd, char *msg) {
	for (int fd = 0; fd <= max_fd; fd++) {
		if (FD_ISSET(fd, &write_fds) && fd != sender_fd)
			send(fd, msg, strlen(msg), MSG_NOSIGNAL);
	}
}

int extract_message(char **buf, char **msg) {
	char *b = *buf;
	char *newbuf;
	int i = 0;

	*msg = 0;
	if (!b)
		return (0);
	while (b[i]) {
		if (b[i] == '\n') {
			newbuf = calloc(1, strlen(b + i + 1) + 1);
			if (!newbuf)
				fatal();
			strcpy(newbuf, b + i + 1); // 1. Copie du reste dans newbuf D'ABORD
			*msg = b;                  // 2. Transfère le pointeur d'origine à msg
			(*msg)[i + 1] = 0;         // 3. Coupe après le '\n'
			*buf = newbuf;             // 4. Met à jour *buf avec le reste
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add) {
	char *newbuf;
	int len = (buf == 0) ? 0 : strlen(buf);

	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		fatal();
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void accept_client(int listen_fd) {
	int client_fd = accept(listen_fd, NULL, NULL);
	if (client_fd < 0)
		return;
	if (client_fd > max_fd)
		max_fd = client_fd;
	clients[client_fd].id = next_id++;
	clients[client_fd].msg = NULL;
	FD_SET(client_fd, &active_fds);

	char buf[100];
	sprintf(buf, "server: client %d just arrived\n", clients[client_fd].id);
	notify_others(client_fd, buf);
}

void remove_client(int fd) {
	char buf[100];
	sprintf(buf, "server: client %d just left\n", clients[fd].id);
	notify_others(fd, buf);

	FD_CLR(fd, &active_fds);
	close(fd);
	if (clients[fd].msg) {
		free(clients[fd].msg);
		clients[fd].msg = NULL;
	}
}

void send_msg(int fd) {
	int read_bytes = recv(fd, buf_read, 4000, 0);
	if (read_bytes <= 0) {
		remove_client(fd);
		return;
	}
	buf_read[read_bytes] = '\0';
	clients[fd].msg = str_join(clients[fd].msg, buf_read);

	char *line = NULL;
	while (extract_message(&clients[fd].msg, &line)) {
		char prefix[50];
		sprintf(prefix, "client %d: ", clients[fd].id);

		char *full_msg = malloc(strlen(prefix) + strlen(line) + 1);
		if (!full_msg)
			fatal();

		strcpy(full_msg, prefix);
		strcat(full_msg, line);
		notify_others(fd, full_msg);

		free(full_msg);
		free(line);
	}
}

int main(int ac, char **av) {
	if (ac != 2) {
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_fd < 0)
		fatal();

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(listen_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		fatal();
	if (listen(listen_fd, 200) < 0)
		fatal();

	FD_ZERO(&active_fds);
	FD_SET(listen_fd, &active_fds);
	max_fd = listen_fd;

	while (1) {
		read_fds = write_fds = active_fds;
		if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max_fd; fd++) {
			if (FD_ISSET(fd, &read_fds)) {
				if (fd == listen_fd)
					accept_client(listen_fd);
				else
					send_msg(fd);
				break;
			}
		}
	}
	return (0);
}
