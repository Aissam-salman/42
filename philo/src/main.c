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

#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

/////////////////////////////////////// STRUCT PHILO

typedef enum e_action
{
	EAT,
	SLEEP,
	THINK,
	TAKE,
	DIED
}					t_action;

typedef struct s_stop
{
	pthread_mutex_t	stop_mutex;
	int				stop;
}					t_stop;

typedef struct s_let
{
	pthread_mutex_t	last_eat_times_mutex;
	size_t			last_eat_times;
}					t_let;

typedef struct s_have_eat
{
	pthread_mutex_t nb_have_eat_mutex;
	size_t			nb_have_eat;
} t_have_eat;

typedef struct s_philo
{
	size_t			index;
	pthread_t		tid;
	t_have_eat			*nb_h_eat;
	t_let			*let;
	struct s_table			*table;
}					t_philo;

typedef struct s_must_be_eat
{
	pthread_mutex_t	nb_times_must_eat_mutex;
	size_t nb_times_must_eat; 
}					t_must_be_eat;

typedef struct s_table
{
	size_t			nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t time_start;
	t_must_be_eat *nb_eat;
	pthread_mutex_t	print_lock;
	t_stop			*stoper;
	pthread_mutex_t	*fork;
	pthread_t		reaper;
	t_philo			*philo;
}					t_table;


/////////////////////////////////////// STRUCT PHILO

void	join_all(t_table *table)
{
	size_t	i;
	t_philo *philo;

	philo = table->philo;
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
	pthread_join(table->reaper, NULL);
}

void	print_action(t_philo *philo, t_action action, int time, int index)
{
	pthread_mutex_lock(&philo->table->stoper->stop_mutex);
	if (philo->table->stoper->stop == 1)
	{
		pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
	if (action == EAT)
		printf("[%d] %d has eat\n", time, index + 1);
	else if (action == SLEEP)
		printf("[%d] %d  is sleeping\n", time, index + 1);
	else if (action == THINK)
		printf("[%d] %d is thinking\n", time, index + 1);
	else if (action == TAKE)
		printf("[%d] %d has take a fork\n", time, index + 1);
	else if (action == DIED)
		printf("[%d] %d died\n", time, index + 1);
}

void	print_params(void)
{
	printf("./philo number_of_philosophers time_to_die");
	printf(" time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	only_digit(char *param)
{
	int	i;

	i = 0;
	if (param[i] == '+')
		i++;
	else if (param[i] == '-')
		return (FALSE);
	while (param[i])
	{
		if (!ft_isdigit(param[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_valid_params(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!only_digit(av[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

size_t	ft_atol(char *str)
{
	int		i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		nb = nb * 10 + (str[i++] - '0');
	return (nb);
}

int	fill_table(t_table *table, char **av)
{
	table->nb_philo = ft_atol(av[1]);
	if (table->nb_philo < 2)
	{
		printf("Insuffisant philo must be > 1");
		return (FALSE);
	}
	table->time_to_die = ft_atol(av[2]);
	if (table->time_to_die == 0)
	{
		printf("Insuffisant time_to_die must be > 0");
		return (FALSE);
	}
	table->time_to_eat = ft_atol(av[3]);
	if (table->time_to_eat == 0)
	{
		printf("Insuffisant time_to_eat must be > 0");
		return (FALSE);
	}
	table->time_to_sleep = ft_atol(av[4]);
	if (av[5])
	{
		table->nb_eat->nb_times_must_eat = ft_atol(av[5]);
		if (table->nb_eat->nb_times_must_eat == 0)
		{
			printf("Insuffisant nb each eat must be > 0");
			return (FALSE);
		}
	}
	return (TRUE);
}

void	print_table(t_table *table)
{
	printf("nb philo: %ld\n", table->nb_philo);
	printf("time_to_die: %ld\n", table->time_to_die);
	printf("time_to_eat: %ld\n", table->time_to_eat);
	printf("time_to_sleep: %ld\n", table->time_to_sleep);
	printf("time_start: %ld ms\n", table->time_start);
	if (table->nb_eat->nb_times_must_eat)
		printf("nb_times_must_eat: %ld\n", table->nb_eat->nb_times_must_eat);
}

size_t get_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}
size_t get_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int eat(t_philo *philo)
{
	struct timeval tv;
	size_t current_time;
	size_t min;
	size_t max;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (1);
	}
	current_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	min = get_min(philo->index, (philo->index + 1) % philo->table->nb_philo);
	max = get_max(philo->index, (philo->index + 1) % philo->table->nb_philo);

	pthread_mutex_lock(&philo->table->fork[min]);
	pthread_mutex_lock(&philo->table->print_lock);
	print_action(philo, TAKE, current_time - philo->table->time_start, philo->index);
	pthread_mutex_unlock(&philo->table->print_lock);

	pthread_mutex_lock(&philo->table->fork[max]);
	pthread_mutex_lock(&philo->table->print_lock);
	print_action(philo, TAKE, current_time - philo->table->time_start, philo->index);
	pthread_mutex_unlock(&philo->table->print_lock);

	pthread_mutex_lock(&philo->table->print_lock);
	print_action(philo, EAT, current_time - philo->table->time_start, philo->index);
	pthread_mutex_unlock(&philo->table->print_lock);


	pthread_mutex_lock(&philo->nb_h_eat->nb_have_eat_mutex);
	philo->nb_h_eat->nb_have_eat++;
	pthread_mutex_unlock(&philo->nb_h_eat->nb_have_eat_mutex);

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (1);
	}
	current_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	pthread_mutex_lock(&philo->let->last_eat_times_mutex);
	philo->let->last_eat_times = current_time;
	pthread_mutex_unlock(&philo->let->last_eat_times_mutex);
	usleep(philo->table->time_to_eat * 1000);

	pthread_mutex_unlock(&philo->table->fork[min]);
	pthread_mutex_unlock(&philo->table->fork[max]);

	return (0);
}

int sleeping(t_philo *philo)
{
	struct timeval tv;
	size_t current_time;

	pthread_mutex_lock(&philo->table->stoper->stop_mutex);
	if (philo->table->stoper->stop == 1)
	{
		pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (1);
	}
	current_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	pthread_mutex_lock(&philo->table->print_lock);
	print_action(philo, SLEEP, current_time - philo->table->time_start, philo->index);
	pthread_mutex_unlock(&philo->table->print_lock);

	usleep(philo->table->time_to_sleep * 1000);

	return (0);

}

int think(t_philo *philo)
{
	struct timeval tv;
	size_t current_time;

	pthread_mutex_lock(&philo->table->stoper->stop_mutex);
	if (philo->table->stoper->stop == 1)
	{
		pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (1);
	}
	current_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	pthread_mutex_lock(&philo->table->print_lock);
	print_action(philo, THINK, current_time - philo->table->time_start, philo->index);
	pthread_mutex_unlock(&philo->table->print_lock);
	usleep(500);
	return (0);
}

void	*thread_routine_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		if (eat(philo))
			return (NULL);
		pthread_mutex_lock(&philo->table->stoper->stop_mutex);
		if (philo->table->stoper->stop == 1)
		{
			pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
		if (sleeping(philo))
			return (NULL);
		pthread_mutex_lock(&philo->table->stoper->stop_mutex);
		if (philo->table->stoper->stop == 1)
		{
			pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
		if (think(philo))
			return (NULL);
		pthread_mutex_lock(&philo->table->stoper->stop_mutex);
		if (philo->table->stoper->stop == 1)
		{
			pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
	}
	return (NULL);
}

void init_philo(t_table *table)
{
	t_philo	*philo;
	size_t	i;
	struct timeval tv;

	philo = malloc(sizeof(t_philo) * table->nb_philo);
	if (!philo)
	{
		printf("malloc\n");
		return ;
	}
	i = 0;
	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return ;
	}
	while (i < table->nb_philo)
	{
		philo[i].table = table;
		philo[i].index = i;
		philo[i].tid = -1;
		philo[i].let = malloc(sizeof(t_let));
		if (!philo[i].let)
			return ;
		philo[i].let->last_eat_times = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		philo[i].nb_h_eat = malloc(sizeof(t_have_eat));
		if (!philo[i].nb_h_eat)
			return ;
		philo[i].nb_h_eat->nb_have_eat = 0;
		i++;
	}
	table->philo = philo;
}

void	init_all_mutex(t_table *table)
{
	size_t	i;
	t_philo *philos;

	philos = table->philo;
	if (pthread_mutex_init(&table->stoper->stop_mutex, NULL) != 0)
		return ;
	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
		return ;
	if (pthread_mutex_init(&table->nb_eat->nb_times_must_eat_mutex, NULL) != 0)
		return ;
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->fork[i], NULL) != 0)
			return ;
		if (pthread_mutex_init(&philos[i].let->last_eat_times_mutex, NULL) != 0)
			return ;
		if (pthread_mutex_init(&philos[i].nb_h_eat->nb_have_eat_mutex, NULL) != 0)
			return ;
		i++;
	}
}

void	destroy_all_mutex(t_table *table)
{
	size_t	i; 
	t_philo *philos;

	philos = table->philo;
	if (pthread_mutex_destroy(&table->stoper->stop_mutex) != 0)
		return ;
	if (pthread_mutex_destroy(&table->print_lock) != 0)
		return ;
	if (pthread_mutex_destroy(&table->nb_eat->nb_times_must_eat_mutex) != 0)
		return ;
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_destroy(&table->fork[i]) != 0)
			return ;
		if (pthread_mutex_destroy(&philos[i].let->last_eat_times_mutex) != 0)
			return ;
		if (pthread_mutex_destroy(&philos[i].nb_h_eat->nb_have_eat_mutex) != 0)
			return ;
		i++;
	}
}

void	*thread_routine_reaper(void *data)
{
	t_table *table;
	size_t i;
	size_t current_time;
	struct timeval tv;
	size_t all_eat;

	table = (t_table *)data;
	while (1)
	{
		i = 0;
		all_eat = 0;
		while (i < table->nb_philo)
		{
			if (gettimeofday(&tv, NULL) == -1)
			{
				perror("gettimeofday");
				return (NULL);
			}
			current_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
			 // *  Mark last eat TE of philo, if (time current - TE) > time_to_die  ->>>> died
			pthread_mutex_lock(&table->philo[i].let->last_eat_times_mutex);
			if ((current_time - table->philo[i].let->last_eat_times) > table->time_to_die)
			{
				pthread_mutex_lock(&table->stoper->stop_mutex);
				table->stoper->stop = 1;
				pthread_mutex_unlock(&table->stoper->stop_mutex);
				pthread_mutex_unlock(&table->philo[i].let->last_eat_times_mutex);
				pthread_mutex_lock(&table->print_lock);
				print_action(&table->philo[i], DIED, current_time - table->time_start, table->philo[i].index);
				pthread_mutex_unlock(&table->print_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&table->philo[i].let->last_eat_times_mutex);

			pthread_mutex_lock(&table->philo[i].nb_h_eat->nb_have_eat_mutex);
			if (table->nb_eat->nb_times_must_eat > 0)
			{
				if (table->philo[i].nb_h_eat->nb_have_eat >= table->nb_eat->nb_times_must_eat)
					all_eat++;

			}
			pthread_mutex_unlock(&table->philo[i].nb_h_eat->nb_have_eat_mutex);
			i++;
		}
		if (table->nb_eat->nb_times_must_eat > 0 && all_eat == table->nb_philo)
		{
				pthread_mutex_lock(&table->stoper->stop_mutex);
				table->stoper->stop = 1;
				pthread_mutex_unlock(&table->stoper->stop_mutex);
				return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

void	run_thread(t_table *table)
{
	size_t	i;
	t_philo *philos;

	philos = table->philo;
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_create(&(philos[i].tid), NULL, thread_routine_philo,
			(void *)&philos[i]);
		if (i % 2 == 0)
			usleep(500);
		i++;
	}
	pthread_create(&table->reaper, NULL, thread_routine_reaper, (void *)table);
}

void free_arr(t_philo *philo, size_t nb_philo)
{
	size_t i;

	if (!philo)
		return;
	i = 0;
	while (i < nb_philo)
	{
		free(philo[i].nb_h_eat);
		free(philo[i].let);
		i++;
	}
	free(philo);
}

void free_all(t_table *table)
{
	if (!table)
		return;
	if (table->philo)
		free_arr(table->philo, table->nb_philo);
	if (table->fork)
		free(table->fork);
	if (table->stoper)
		free(table->stoper);
	if (table->nb_eat)
		free(table->nb_eat);
	free(table);
}

void	init(char **av)
{
	t_table			*table;
	struct timeval	tv;

	table = malloc(sizeof(t_table));
	if (!table)
		return ;
	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return ;
	}
	table->time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	table->nb_eat = malloc(sizeof(t_must_be_eat));
	if (!table->nb_eat)
	{
		printf("malloc\n");
		return ;
	}
	table->nb_eat->nb_times_must_eat = 0;
	if (!fill_table(table, av))
		return ;
	table->fork = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->fork)
	{
		printf("malloc\n");
		return ;
	}
	table->stoper = malloc(sizeof(t_stop));
	if (!table->stoper)
	{
		printf("malloc\n");
		return ;
	}
	table->stoper->stop = 0;
	init_philo(table);
	init_all_mutex(table);
	run_thread(table);
	join_all(table);
	destroy_all_mutex(table);
	free_all(table);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error params.\n");
		print_params();
		return (EXIT_FAILURE);
	}
	if (!is_valid_params(ac, av))
	{
		printf("Invalid params.\n");
		print_params();
		return (EXIT_FAILURE);
	}
	init(av);
	return (EXIT_SUCCESS);
}
