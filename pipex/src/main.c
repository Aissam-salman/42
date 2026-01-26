/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:12:15 by alamjada          #+#    #+#             */
/*   Updated: 2026/01/26 11:28:46 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct s_cmd
{
	char *name;
	char *path;
	char **args;
	int *pipeline;
}	t_cmd;

void free_array(char **arr)
{
	int i;

	if (!arr || !*arr)
		return;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void clear_cmd(t_cmd **cmd)
{
	if ((*cmd)->args)
		free_array((*cmd)->args);
	if ((*cmd)->pipeline[0])
		close((*cmd)->pipeline[0]);
	if ((*cmd)->pipeline[1])
		close((*cmd)->pipeline[1]);
	if ((*cmd)->path)
		free((*cmd)->path);
	free(*cmd);
}


void	check_infile(char *filename)
{
	if (access(filename, R_OK) == -1)
	{
		ft_printf("zsh: %s: %s\n", strerror(errno), filename);
		exit(errno);
	}
}

void	check_filename(char *filename)
{
	int fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_printf("zsh: %s: %s\n", strerror(errno), filename);
		exit(errno);
	}
	close(fd);
}

void	error_program(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void error_no(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void check_cmd(int ac, char **av)
{
	int i; 
	(void)av;

	i = 2;
	while (i < ac - 1)
	{
		// char *cmd = av[i];
		// char **splited = ft_split(cmd, ' ');
		// char *path ;
		// (void)splited;
		// ()
		i++;
	}
}

#define ENV_PATH "PATH="

int start_with(char *txt, char *word_start)
{
	int i;

	i = 0;
	while (word_start[i] && txt[i])
	{
		if (word_start[i] != txt[i])
			return (0);
		i++;
	}
	return (1);
}

char **extract_path(char **envp)
{
	int i;
	char *line;
	char **path;

	i = 0;
	while (envp[i])
	{
		if (start_with(envp[i], ENV_PATH))
			break;
		i++;
	}
	line = envp[i] + ft_strlen(ENV_PATH);
	path = ft_split(line, ':');
	i = 0;
	while (path[i])
	{
		char *old = path[i];
		path[i] = ft_strjoin(old, "/");
		free(old);
		old = NULL;
		i++;
	}
	for(int i = 0; path[i]; i++)
		printf("[%d]= %s\n", i, path[i]);
	return (path);
}

int main(int ac, char **av, char **envp)
{
	t_cmd *cmd;
	int pipe_fd[2];

	//NOTE: parsing params
	if (ac < 4)
		error_program("Pipex: need \"./pipex file1 cmd1 file2\" minimal.");
	check_infile(av[1]);
	check_filename(av[ac - 1]);
	char **env = extract_path(envp);
	free_array(env);
	exit(0);

	check_cmd(ac, av);

	//NOTE: CMD args
	if (pipe(pipe_fd) == -1)
		error_no("pipe");
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		error_no("malloc");
	char **args = ft_split(av[1], ' ');
	cmd->name = args[0];
	cmd->path = ft_strjoin("/bin/", args[0]);
	cmd->args = args;
	cmd->pipeline = pipe_fd;
	clear_cmd(&cmd);
	return (0);
}
