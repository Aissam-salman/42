/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:50:34 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/19 19:24:02 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int ft_error(char *msg) {
  int i;

  i = 0;
  while (msg[i])
    write(2, &msg[i++], 1);
  return (1);
}

int ft_cd(char **argv, int i) {
  if (i != 2)
    return (ft_error("error: cd: bad arguments\n"));
  else if (chdir(argv[1]) == -1)
    return (ft_error("error: cd: cannot change directory to "),
            ft_error(argv[1]), ft_error("\n"));
  return (0);
}

int ft_exec(char **argv, char **envp, int i) {
  int pipe_fd[2];
  int status;
  int have_pipe;
  int pid;

  have_pipe = argv[i] && !strcmp(argv[i], "|");

  if (have_pipe && pipe(pipe_fd) == -1)
    return (ft_error("error: fatal\n"));
  pid = fork();
  if (pid == 0) {
    argv[i] = 0;
    if (have_pipe && (dup2(pipe_fd[1], 1) == -1 || close(pipe_fd[0]) == -1 ||
                      close(pipe_fd[1]) == -1))
      return (ft_error("error: fatal\n"));
    execve(*argv, argv, envp);
    return (ft_error("error: cannot execute "), ft_error(*argv),
            ft_error("\n"));
  }
  waitpid(pid, &status, 0);
  if (have_pipe && (dup2(pipe_fd[0], 0) == -1 || close(pipe_fd[0]) == -1 ||
                    close(pipe_fd[1]) == -1))
    return (ft_error("error: fatal\n"));
  return (WIFEXITED(status) && WEXITSTATUS(status));
}

int microshell(char **argv, char **envp) {

  int status;
  int i;

  i = 0;
  status = 0;
  while (argv[i] && argv[++i]) {
    argv += i;
    i = 0;
    while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
      i++;
    if (!strcmp(*argv, "cd"))
      status = ft_cd(argv, i);
    else if (i)
      status = ft_exec(argv, envp, i);
  }
  return (status);
}

int main(int argc, char **argv, char **envp) {
  int status;

  status = 0;
  if (argc > 1)
    status = microshell(argv, envp);
  return (status);
}

/*

Assignment name  : microshell
Expected files   : microshell.c
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill,
exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Write a program that will behave like executing a shell command
- The command line to execute will be the arguments of this program
- Executable's path will be absolute or relative but your program must not build
a path (from the PATH variable for example)
- You must implement "|" and ";" like in bash
        - we will never try a "|" immediately followed or preceded by nothing or
"|" or ";"
- Your program must implement the built-in command cd only with a path as
argument (no '-' or without parameters)
        - if cd has the wrong number of argument your program should print in
STDERR "error: cd: bad arguments" followed by a '\n'
        - if cd failed your program should print in STDERR "error: cd: cannot
change directory to path_to_change" followed by a '\n' with path_to_change
replaced by the argument to cd
        - a cd command will never be immediately followed or preceded by a "|"
- You don't need to manage any type of wildcards (*, ~ etc...)
- You don't need to manage environment variables ($BLA ...)
- If a system call, except execve and chdir, returns an error your program
should immediatly print "error: fatal" in STDERR followed by a '\n' and the
program should exit
- If execve failed you should print "error: cannot execute
executable_that_failed" in STDERR followed by a '\n' with executable_that_failed
replaced with the path of the failed executable (It should be the first argument
of execve)
- Your program should be able to manage more than hundreds of "|" even if we
limit the number of "open files" to less than 30.

for example this should work:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my
microshell microshell i love my microshell
$>

Hints:
Don't forget to pass the environment variable to execve

Hints:
Do not leak file descriptors!%
*/
