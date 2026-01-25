/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:15 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/19 16:13:20 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "../lib/libft/includes/libft.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	int id = fork();
	int n;
	if (id == 0)
		n = 1;
	else
		n = 22;
	if (id != 0)
		wait(NULL);
	int i = n;
	while (i < n + 5)
	{
		printf("%d ", i++);
		fflush(stdout);
	}
	if (id == 0)
		printf("\n");
	return (0);
	// int i = 0;
	// while (env[i])
	// {
	// 	printf("%s", env[i]);
	// 	i++;
	// }

	// int fd = open("tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// if (!fd)
	// 	exit(EXIT_FAILURE);
	// char *newarg[] = {"which", "ls", NULL};
	// int stdo = dup(1);
	// dup2(fd, 1);
	// if (execve("/bin/which", newarg, env) == -1)
	// {
	// 	perror("execve");
	// }
	// char *cmd_path = get_next_line(fd);
	// dup2(stdo, fd);
	// close(fd);
	//
	// char *newarg2[] = {"ls", NULL};
	// execve(cmd_path,newarg2, env);
	// perror("execve 2");
	//
	// close(stdo);
}
