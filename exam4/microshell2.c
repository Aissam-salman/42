/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:01:18 by salman            #+#    #+#             */
/*   Updated: 2026/04/19 19:45:17 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int ft_error(char *msg) {
  int i = 0;
  while (msg[i])
    i++;
  write(2, msg, i);
  return (1);
}

int ft_cd(char **av, int i) {
  if (i != 2)
    return (ft_error("error: cd: bad arguments\n"));
  else if (chdir(av[1]) == -1)
    return (ft_error("error: cd: cannot change directory to "), ft_error(av[1]),
            ft_error("\n"));
  return (0);
}

int ft_exec(char **av, char **envp, int i) {
  int pipe_fd[2];
  int status = 0;
  int have_pipe = av[i] && !strcmp(av[i], "|");
  int pid;

  if (have_pipe && pipe(pipe_fd) == -1)
    return (ft_error("error: fatal\n"));
  pid = fork();
  if (pid == -1)
    return (ft_error("error: fatal\n"));

  if (pid == 0) {
    if (have_pipe && (dup2(pipe_fd[1], STDOUT_FILENO) == -1 ||
                      close(pipe_fd[0]) == -1 || close(pipe_fd[1]) == -1))
      return (ft_error("error: fatal\n"));

    av[i] = 0;

    execve(*av, av, envp);
    ft_error("error: cannot execute ");
    ft_error(*av);
    ft_error("\n");
    exit(1);
  }
  if (have_pipe && (dup2(pipe_fd[0], STDIN_FILENO) == -1 ||
                    close(pipe_fd[0]) == -1 || close(pipe_fd[1]) == -1))
    return (ft_error("error: fatal\n"));
  if (!have_pipe) {
    waitpid(pid, &status, 0);
    while (waitpid(-1, NULL, 0) != -1)
      ;
  }
  return (WIFEXITED(status) && WEXITSTATUS(status));
}

int microshell(char **av, char **envp) {
  int status;
  int i;

  i = 0;
  status = 0;
  int init_stdin = dup(0);
  while (av[i] && av[++i]) {
    av += i;
    i = 0;
    while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
      i++;
    if (i == 0)
      continue;
    if (!strcmp(*av, "cd"))
      status = ft_cd(av, i);
    else if (i)
      status = ft_exec(av, envp, i);
    if (av[i] && !strcmp(av[i], ";"))
      dup2(init_stdin, 0);
  }
  dup2(init_stdin, 0); // Restore stdin even if there is no ';' at the end
  close(init_stdin);
  return (status);
}

int main(int ac, char **av, char **envp) {
  int status;

  status = 0;
  if (ac > 1)
    status = microshell(av, envp);
  return (status);
}
