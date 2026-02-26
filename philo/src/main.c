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

/*
// cc -pthread -fsanitize=thread -g  (contre data race)
 *  1 seconds = 1000 milli
 *  1000 microseconds = 1 milliseconds   formula
	/ 1000  usleep(1* 1000) for 1 mls
 *
 *  ac -> min 5, max 6

	*  ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
 *
 *  philo 1 -> N
 *
 *  Debut: mark T0 avec le timestamps gettimeofday * 1000
 *  Ta(nv timestamps a chq action) - T0 = timestamps a afficher
 *
 *  Mark last eat TE of philo, if (time current - TE) > time_to_die  ->>>> died
 *
 *  print X whith the philo number
 *  timestamp_in_ms X has taken a fork
 *  timestamp_in_ms X is eating
 *  timestamp_in_ms X is sleeping
 *  timestamp_in_ms X is thinking
 *  timestamp_in_ms X died , dans les 10ms of their actual death
 *
 *  Monitor qui verif si un philo est mort et arret la simu si oui
 *
 * pthread_mutex_t forks[5];
 */
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

typedef struct s_philo
{
	size_t			index;
	pthread_t		tid;
	size_t			nb_times_must_eat;
	t_let			*let;
	struct s_table			*table;
	// ?? state ? t_action
}					t_philo;

typedef struct s_table
{
	size_t			nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t time_start;        // ?? mutex
	size_t nb_times_must_eat; // ?? mutex
	pthread_mutex_t	print_lock;
	t_stop			*stoper;
	pthread_mutex_t	*fork;
	pthread_t		reaper;
	t_philo			*philo;
}					t_table;


/////////////////////////////////////// STRUCT PHILO

void	print_action(t_action action, int time, int index)
{
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
		table->nb_times_must_eat = ft_atol(av[5]);
		if (table->time_to_eat == 0)
		{
			printf("Insuffisant time_to_eat must be > 0");
			return (FALSE);
		}
	}
	else
		table->nb_times_must_eat = 0;
	return (TRUE);
}

void	print_table(t_table *table)
{
	printf("nb philo: %ld\n", table->nb_philo);
	printf("time_to_die: %ld\n", table->time_to_die);
	printf("time_to_eat: %ld\n", table->time_to_eat);
	printf("time_to_sleep: %ld\n", table->time_to_sleep);
	printf("time_start: %ld ms\n", table->time_start);
	if (table->nb_times_must_eat)
		printf("nb_times_must_eat: %ld\n", table->nb_times_must_eat);
}

void	*thread_routine_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	// loop tant que vivant  eat -> sleep -> think
	//*  Mark last eat TE of philo, if (time current - TE) > time_to_die
	// ->>>> died
	(void)philo;
	// pthread_t	tid;
	// t_counter	*counter;
	// int			i;
	//
	// tid = pthread_self();
	// counter = (t_counter *)data;
	// pthread_mutex_lock(&counter->count_mutex);
	// printf("Thread [%ld]: count start: %d\n", tid, counter->count);
	// pthread_mutex_unlock(&counter->count_mutex);
	// i = 0;
	// while (i < TIMES)
	// {
	// 	pthread_mutex_lock(&counter->count_mutex);
	// 	counter->count++;
	// 	pthread_mutex_unlock(&counter->count_mutex);
	// 	i++;
	// }
	// pthread_mutex_lock(&counter->count_mutex);
	// printf("Thread [%ld]: count final: %d\n", tid, counter->count);
	// pthread_mutex_unlock(&counter->count_mutex);
	return (NULL);
}

void init_philo(t_table *table)
{
	t_philo	*philo;
	size_t	i;

	philo = malloc(sizeof(t_philo) * table->nb_philo);
	if (!philo)
	{
		printf("malloc\n");
		return ;
	}
	i = 0;
	while (i < table->nb_philo)
	{
		philo[i].table = table;
		philo[i].index = i;
		philo[i].tid = -1;
		philo[i].let = malloc(sizeof(t_let));
		if (!philo[i].let)
			return ;
		philo[i].let->last_eat_times = 0;
		philo[i].nb_times_must_eat = table->nb_times_must_eat;
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
	i = 0;
	while (i < table->nb_times_must_eat)
	{
		if (pthread_mutex_init(&table->fork[i], NULL) != 0)
			return ;
		if (pthread_mutex_init(&philos[i].let->last_eat_times_mutex, NULL) != 0)
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
	i = 0;
	while (i < table->nb_times_must_eat)
	{
		if (pthread_mutex_destroy(&table->fork[i]) != 0)
			return ;
		if (pthread_mutex_destroy(&philos[i].let->last_eat_times_mutex) != 0)
			return ;
		i++;
	}
}

void	*thread_routine_reaper(void *data)
{
	t_table *table;

	table = (t_table *)data;
	printf("FROM reaper\n");
	print_table(table);
	printf("REAPER DONE");
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
		pthread_create(&philos[i].tid, NULL, thread_routine_philo,
			(void *)&philos[i]);
		// WARN: maybe need split time for precision
		usleep(table->time_to_eat / 1000);
		i++;
	}
	pthread_create(&table->reaper, NULL, *thread_routine_reaper, (void *)table);
}

void	join_all(t_table *table, t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(philo[i].tid, NULL);
		i++;
	}
	pthread_join(table->reaper, NULL);
}

void	init(char **av)
{
	t_table			*table;
	struct timeval	tv;

	table = malloc(sizeof(t_table));
	if (!table)
		return ;
	if (!fill_table(table, av))
		return ;
	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return ;
	}
	table->time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	table->fork = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->fork)
	{
		printf("malloc\n");
		return ;
	}
	table->stoper = malloc(sizeof(t_stop));
	if (!table)
	{
		printf("malloc\n");
		return ;
	}
	table->stoper->stop = 0;
	init_philo(table);
	init_all_mutex(table);
	run_thread(table);
	// join_all(table, philosophers);
	print_table(table);
	printf("OK\n");
	destroy_all_mutex(table);
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
	printf("\n=====INPUT=======\n");
	printf("nb philo: %s, ", av[1]);
	printf("time_to_die: %s, ", av[2]);
	printf("time_to_eat: %s, ", av[3]);
	printf("time_to_sleep: %s", av[4]);
	if (av[5])
	{
		printf(", ");
		printf("nb_times_must_eat: %s", av[5]);
	}
	printf("\n");
	printf("\n=====PARSING======\n");
	init(av);
	return (EXIT_SUCCESS);
}
