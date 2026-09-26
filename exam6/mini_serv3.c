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

void fatal(void);

void notify(int sender_fd, char *msg);
char *ft_strjoin(char *b, char *add);
int extract_msg(char **buf, char **msg);
void accept_client(int fd);
void remove_client(int fd);
void send_msg(int fd);
int create_socket(int port);
int main(int ac, char **av) {
	return 0;
}
