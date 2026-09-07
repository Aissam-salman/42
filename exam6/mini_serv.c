/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <alamjada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 11:02:23 by salman            #+#    #+#             */
/*   Updated: 2026/09/07 16:08:44 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

// ============================================================
// 1. STRUCTURE CLIENT + GLOBALES
// ============================================================

typedef struct s_client {
    int fd;
    int id;
    char *buff_send; // ce qu'on doit encore envoyer a ce client
    char *buff_read; // ce qu'on a recu mais qui ne forme pas encore une ligne
    struct s_client *next_client;
} t_client;

t_client *g_clients = NULL;
int g_next_id = 0;
int g_max_fd = 0;

// ============================================================
// 2. UTILITAIRES
// ============================================================

int ft_strlen(char *str) {
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void err(char *msg) {
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    exit(1);
}

// concatene "add" a la fin de "buf" (buf peut etre NULL). free l'ancien buf.
char *str_join(char *buf, char *add) {
    int len = 0;
    char *newbuf;

    if (buf)
        len = ft_strlen(buf);
    newbuf = malloc(sizeof(char) * (len + ft_strlen(add) + 1));
    if (!newbuf)
        err("Fatal error");
    newbuf[0] = '\0';
    if (buf)
        strcpy(newbuf, buf);
    strcat(newbuf, add);
    free(buf);
    return newbuf;
}

// si *buf contient une ligne complete (\n), la met dans *msg et la retire
// de *buf. retourne 1 si une ligne a ete extraite, 0 sinon.
int extract_message(char **buf, char **msg) {
    char *newbuf;
    int i = 0;

    *msg = NULL;
    if (*buf == NULL)
        return 0;
    while ((*buf)[i]) {
        if ((*buf)[i] == '\n') {
            newbuf = calloc(1, ft_strlen(*buf + i + 1) + 1);
            if (!newbuf)
                err("Fatal error");
            strcpy(newbuf, *buf + i + 1);
            *msg = *buf;
            (*msg)[i + 1] = '\0';
            *buf = newbuf;
            return 1;
        }
        i++;
    }
    return 0;
}

// ============================================================
// 3. GESTION DE LA LISTE DE CLIENTS
// ============================================================

t_client *add_client(int fd) {
    t_client *new_client = malloc(sizeof(t_client));

    if (!new_client)
        err("Fatal error");
    new_client->fd = fd;
    new_client->id = g_next_id++;
    new_client->buff_send = NULL;
    new_client->buff_read = NULL;
    new_client->next_client = g_clients;
    g_clients = new_client;
    return new_client;
}

void remove_client(t_client *target) {
    t_client *curr = g_clients;
    t_client *prev = NULL;

    while (curr) {
        if (curr == target) {
            if (prev)
                prev->next_client = curr->next_client;
            else
                g_clients = curr->next_client;
            close(curr->fd);
            free(curr->buff_send);
            free(curr->buff_read);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next_client;
    }
}

// ajoute msg au buffer d'envoi de tous les clients sauf "except"
void send_to_all(t_client *except, char *msg) {
    t_client *curr = g_clients;

    while (curr) {
        if (curr != except)
            curr->buff_send = str_join(curr->buff_send, msg);
        curr = curr->next_client;
    }
}

// ============================================================
// 4. SOCKET
// ============================================================

int create_socket(int port) {
    struct sockaddr_in saddr;
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd == -1)
        err("Fatal error");

    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1

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

// ============================================================
// 5. BOUCLE PRINCIPALE
// ============================================================

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
            curr = curr->next_client;
        }

        if (select(g_max_fd + 1, &read_fds, &write_fds, NULL, NULL) == -1)
            continue;

        // --- NOUVELLE CONNEXION ---
        if (FD_ISSET(server_fd, &read_fds)) {
            int new_fd = accept(server_fd, NULL, NULL);
            // FD_SET sur un fd >= FD_SETSIZE ecrit hors du fd_set : on refuse
            // la connexion plutot que de corrompre la pile.
            if (new_fd >= FD_SETSIZE) {
                close(new_fd);
            } else if (new_fd >= 0) {
                t_client *new_client = add_client(new_fd);
                sprintf(msg, "server: client %d just arrived\n", new_client->id);
                send_to_all(new_client, msg);
            }
        }

        // --- LECTURE / ECRITURE ---
        curr = g_clients;
        while (curr) {
            t_client *next = curr->next_client; // sauvegarde avant suppression
            int disconnected = 0;

            if (FD_ISSET(curr->fd, &read_fds)) {
                int ret = recv(curr->fd, buf, sizeof(buf) - 1, 0);
                if (ret <= 0) {
                    sprintf(msg, "server: client %d just left\n", curr->id);
                    send_to_all(curr, msg);
                    remove_client(curr);
                    disconnected = 1;
                } else {
                    buf[ret] = '\0';
                    curr->buff_read = str_join(curr->buff_read, buf);

                    char *line;
                    while (extract_message(&curr->buff_read, &line)) {
                        sprintf(msg, "client %d: ", curr->id);
                        t_client *dest = g_clients;
                        while (dest) {
                            if (dest != curr) {
                                dest->buff_send = str_join(dest->buff_send, msg);
                                dest->buff_send =
                                    str_join(dest->buff_send, line);
                            }
                            dest = dest->next_client;
                        }
                        free(line);
                    }
                }
            }

            if (!disconnected && FD_ISSET(curr->fd, &write_fds) &&
                curr->buff_send) {
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
                    // envoi partiel : on garde ce qui n'est pas parti
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
