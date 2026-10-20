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
int max_fd = 0;
int next_id = 0;
fd_set active_fds, read_fds, write_fds;
char bread[4024];

void fatal(void){
	write(2, "Fatal error\n", 12);
	exit(1);
}

void notify(int sender_fd, char *msg) {
	for (int fd = 0; fd <= max_fd; fd++) {
		if (FD_ISSET(fd, &write_fds) && sender_fd != fd) {
			send(fd, msg, strlen(msg), MSG_NOSIGNAL);
		}
	}
}

char *strjoin(char *b, char *add) {
	char *dest;
	int i = 0;

	if (b)
		i = strlen(b);
	dest = malloc(i + strlen(add) + 1);
	if (!dest)
		fatal();
	dest[0] = '\0';
	if (b)
		strcpy(dest, b);
	strcat(dest, add);
	free(b);
	return dest;
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

void accept_clients(int fd) {
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
	sprintf(buf, "server: client %d just arrived\n", clients[client_fd].id);
	notify(client_fd, buf);
	
}
void send_msg(int fd);
int create_socket(int port);
int main(int ac, char **av);




