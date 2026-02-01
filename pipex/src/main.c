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
#include <sys/wait.h>
#include <unistd.h>

#define ENV_PATH "PATH="

typedef struct s_cmd
{
	char *name;
	char *path;
	char **args;
	struct s_cmd *next;
}	t_cmd;

typedef struct s_pipex
{
	char **env;
	t_cmd *cmd;
	int pipeline[2];
} t_pipex;

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

void	free_list(t_cmd **lst)
{
	t_cmd	*head;
	t_cmd	*tmp;

	if (!lst || !*lst)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head->next;
		if (head->args)
			free_array(head->args);
		if (head->path)
			free(head->path);
		if (head->name)
			free(head->name);
		free(head);
		head = tmp;
	}
	*lst = NULL;
}

void clear_pipex(t_pipex *pipex)
{
	if (pipex->env)
		free_array(pipex->env);
	free_list(&pipex->cmd);
	free(pipex->cmd);
	// close_arr(pipex->pipeline)
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
	exit(errno);
}


int start_with(char *txt, char *word_start)
{
	int i;

	if (!txt || !word_start)
		return (-1);
	i = 0;
	while (word_start[i] && txt[i])
	{
		if (word_start[i] != txt[i])
			return (0);
		i++;
	}
	return (1);
}

char *ft_cutname(char *path)
{
	char *name;
	int end;
	int size;
	int i;

	end = ft_strlen(path) - 1;
	size = 0;
	while (path[end] != '/')
	{
		size++;
		end--;
	}
	name = malloc(size + 1);
	if (!name)
		return (NULL);
	i = 0;
	while (path[++end])
		name[i++] = path[end];
	name[i] = '\0';
	return (name);
}

void check_cmd(int ac, t_pipex *pipex)
{
	int i; 
	int j;
	int is_access;
	char *complet_path;
	t_cmd *head;

	i = 2;
	head = pipex->cmd;
	while (i < ac - 1)
	{
		is_access = 0;
		if (start_with(head->args[0], "/"))
		{
			if (access(head->args[0], X_OK) == 0)
			{
				is_access = 1;
				head->path = ft_strdup(head->args[0]);
				head->name = ft_cutname(head->args[0]);
			}
		}
		else 
		{
			j = 0;
			while (pipex->env[j])
			{
				complet_path = ft_strjoin(pipex->env[j], head->args[0]);
				if (access(complet_path, X_OK) == 0)
				{
					is_access = 1;
					head->path = ft_strdup(complet_path);
					head->name = ft_strdup(head->args[0]);
					break;
				}
				free(complet_path);
				complet_path = NULL;
				j++;
			}
			if (complet_path)
			{
				free(complet_path);
				complet_path = NULL;
			}
		}
		if (is_access == 0)
			error_no("path");
		head = head->next; i++;
	}
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
	//FIX: handle cmd with "" '' like awk '{print $1}'
	//    don't separe text, need new split
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
	return (path);
}

void init(t_pipex *pipex)
{
	pipex->env = NULL;
	pipex->cmd = NULL;
}

t_cmd	*ft_cmd_last(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_cmd_back(t_cmd **lst, t_cmd *new_node)
{
	t_cmd	*last;

	if (!lst || !new_node)
		return ;
	if (!*lst)
		*lst = new_node;
	else
	{
		last = ft_cmd_last(*lst);
		last->next = new_node;
	}
}

t_cmd *ft_new_cmd()
{
	t_cmd *cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		error_no("malloc");
	cmd->args = NULL;
	cmd->name = NULL;
	cmd->path = NULL;
	cmd->next = NULL;
	return (cmd);
}

int main(int ac, char **av, char **envp)
{
	t_pipex pipex;
	int i;
	t_cmd *head;
	int pids[ac - 3];
	int out_fd;
	int inf_fd;
	int status;

	if (ac < 4)
		error_program("Pipex: need \"./pipex file1 cmd1 file2\" minimal.");
	check_infile(av[1]);
	check_filename(av[ac - 1]);
	init(&pipex);
	pipex.env = extract_path(envp);
	i = 2;
	while (i <  ac - 1)
	{
		t_cmd *new_cmd = ft_new_cmd();
		new_cmd->args = ft_split(av[i], ' ');
		ft_cmd_back(&pipex.cmd, new_cmd);
		i++;
	}
	check_cmd(ac, &pipex);
	inf_fd = open(av[1], O_RDONLY);
	dup2(inf_fd, 0);
	close(inf_fd);
	head = pipex.cmd;
	i = 0;
	while (pipex.cmd->next)
	{
		if (pipe(pipex.pipeline) == -1)
			error_no("pipe");
		pids[i] = fork();
		if (pids[i] == 0)
		{
			dup2(pipex.pipeline[1], 1);
			close(pipex.pipeline[0]);
			close(pipex.pipeline[1]);
			execv(pipex.cmd->path, pipex.cmd->args);
		}
		else
		{
			dup2(pipex.pipeline[0], 0);
			close(pipex.pipeline[1]);
			close(pipex.pipeline[0]);
		}
		pipex.cmd = pipex.cmd->next;
		i++;
	}
	out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd == -1)
		error_no("open");
	pids[i] = fork();
	if (pids[i] == 0)
	{
		dup2(out_fd, 1);
		close(out_fd);
		execv(pipex.cmd->path, pipex.cmd->args);
	}
	close(out_fd);
	i = 0;
	pipex.cmd = head;
	while (head)
	{
		waitpid(pids[i], &status, 0);
		i++;
		head = head->next;
	}
	clear_pipex(&pipex);
	return (EXIT_SUCCESS);
}
