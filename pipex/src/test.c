/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:01:10 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/26 11:30:25 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	int pipe_fd[2];

	// open pipe
	if (pipe(pipe_fd) == -1)
		return (1);

	// subprocess
	int pid1 = fork();
	// error fork
	if (pid1 < 0)
		return (2);

	if (pid1 == 0)
	{
		// child process 1 ls
		char *argv[] = {"ls", NULL};
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execv("/bin/ls", argv);
		// STOP HERE
	}

	int pid2 = fork();
	if (pid2 < 0)
		return (3);

	if (pid2 == 0)
	{
		char *argv[] = {"wc","-l", NULL};
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execv("/usr/bin/wc", argv);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
