/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:57:41 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/11 08:59:29 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

int	ft_end(char *stash)
{
	if (!stash)
		return (0);
	if (ft_strnstr(stash, "0000000011111111", ft_strlen(stash)))
		return (1);
	return (0);
}

void	ft_convert_to_char(char *stash)
{
	size_t	i;
	int		b;
	char	*c;

	i = 0;
	while (1)
	{
		c = ft_substr(&stash[i], 0, 8);
		if (!c)
			break ;
		if (ft_strncmp(&stash[i], "0000000011111111", 16) == 0)
		{
			free(c);
			break ;
		}
		i += 8;
		b = ft_atoi_base(c, "01");
		free(c);
		ft_putchar_fd((char)b, 1);
	}
}

// TODO: NORME42
void	signal_callback_handler(int sig)
{
	static char	*stash;
	char		*old;

	old = stash;
	if (sig == SIGUSR1)
		stash = ft_strjoin(stash, "0");
	else if (sig == SIGUSR2)
		stash = ft_strjoin(stash, "1");
	free(old);
	if (!stash)
		return ;
	if (ft_strlen(stash) > 15 && ft_end(stash))
	{
		ft_convert_to_char(stash);
		ft_putchar_fd('\n', 1);
		// free(stash);
		stash = NULL;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_bzero(&sa, sizeof(sa));
	ft_printf("PID Server: %d\n", pid);
	sa.sa_handler = &signal_callback_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
