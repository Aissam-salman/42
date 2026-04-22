/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell14.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:51:57 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/22 14:52:27 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void ft_err(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
	{
		while (*arg)
			write(2, arg++, 1);
	}
	write(2, "\n", 1);
}

void ft_fatal(void)
{
	ft_err("error: fatal", NULL);
	exit(1);
}

int ft_cd(char **av, int i)
{
	if (i != 2)
	{
		ft_err("error: cd: bad arguments", NULL);
		return (1);
	}
	else if (chdir(av[1]) == -1)
	{
		ft_err("error: cd: cannot move to directory ", av[1]);
		return (1);
	}
	return (0);
}

int ft_exec(char **av, int i, int *tmp_fd, char **envp)
{
	int status = 0;
	int fd[2];
	pid_t pid;
	int is_pipe = (av[i] && strcmp(av[i], "|") == 0);

	if (is_pipe && pipe(fd) == -1)
		ft_fatal();

	pid = fork();
	if (pid < 0)
		ft_fatal();
	if (pid == 0)
	{
		av[i] = NULL;
		if (dup2(*tmp_fd, STDIN_FILENO) == -1)
			ft_fatal();
		if (is_pipe)
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				ft_fatal();
			close(fd[0]);
			close(fd[1]);
		}
		close(*tmp_fd);
		if (execve(*av, av, envp) == -1)
		{
			ft_err("error: cannot execute ", *av);
			exit(1);
		}
	}
	else 
	{
		close(*tmp_fd);
		if (is_pipe)
		{
			close(fd[1]);
			*tmp_fd = fd[0];
		}
		else
		{
			waitpid(pid, &status, 0);
			while(waitpid(-1, NULL, 0) != -1)
				;
			*tmp_fd = dup(STDIN_FILENO);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
		}
	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
	int status = 0;
	int i = 0;
	int tmp_fd = dup(STDIN_FILENO);
	(void)ac;

	while (av[i] && av[++i])
	{
		av += i;
		i = 0;
		while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
			i++;
		if (strcmp(av[0], "cd") == 0)
			status = ft_cd(av, i);
		else if (i > 0)
			status = ft_exec(av, i, &tmp_fd, envp);
	}
	close(tmp_fd);
	return (status);
}
