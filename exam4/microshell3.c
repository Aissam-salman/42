#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

// LEARN THIS VERSION

void ft_putstr_err(char *str, char *arg) {
	while (*str) write(2, str++, 1);
	if (arg)
		while (*arg) write(2, arg++, 1);
	write(2, "\n", 1);
}

void ft_fatal(void) {
	ft_putstr_err("error: fatal", NULL);
	exit(1);
}

int ft_cd(char **argv, int i) {
	if (i != 2) {
		ft_putstr_err("error: cd: bad arguments", NULL);
		return 1;
	} else if (chdir(argv[1]) == -1) {
		ft_putstr_err("error: cd: cannot change directory to ", argv[1]);
		return 1;
	}
	return 0;
}

int ft_execute(char **argv, int i, int *tmp_fd, char **envp) {
	int fd[2];
	int status = 0;
	int next_is_pipe = (argv[i] && strcmp(argv[i], "|") == 0);

	if (next_is_pipe && pipe(fd) == -1) ft_fatal();

	pid_t pid = fork();
	if (pid < 0) ft_fatal();

	if (pid == 0) {
		argv[i] = NULL;
		if (dup2(*tmp_fd, STDIN_FILENO) == -1) ft_fatal();
		if (next_is_pipe) {
			if (dup2(fd[1], STDOUT_FILENO) == -1) ft_fatal();
			close(fd[0]);
			close(fd[1]);
		}
		close(*tmp_fd);
		if (execve(argv[0], argv, envp) == -1) {
			ft_putstr_err("error: cannot execute ", argv[0]);
			exit(1);
		}
	} else {
		close(*tmp_fd);
		if (next_is_pipe) {
			close(fd[1]);
			*tmp_fd = fd[0];
		} else {
			waitpid(pid, &status, 0);
			while (waitpid(-1, NULL, 0) != -1);
			*tmp_fd = dup(STDIN_FILENO);
			if (WIFEXITED(status))
				return WEXITSTATUS(status);
		}
	}
	return 0;
}

int main(int argc, char **argv, char **envp) {
	int i = 0;
	int tmp_fd;
	int status = 0;

	(void)argc;
	tmp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1]) {
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
			i++;

		if (strcmp(argv[0], "cd") == 0)
			status = ft_cd(argv, i);
		else if (i > 0)
			status = ft_execute(argv, i, &tmp_fd, envp);
	}
	close(tmp_fd);
	return status;
}