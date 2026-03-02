/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:13:35 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:38:49 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static int	init_philo(t_table *table)
{
	t_philo	*philo;
	size_t	i;

	philo = malloc(sizeof(t_philo) * table->nb_philo);
	if (!philo)
		return (1);
	i = 0;
	while (i < table->nb_philo)
	{
		philo[i].table = table;
		philo[i].index = i;
		philo[i].tid = -1;
		philo[i].let = malloc(sizeof(t_let));
		if (!philo[i].let)
			return (1);
		if (get_current_time(&philo[i].let->last_eat_times) == -1)
			return (1);
		philo[i].nb_h_eat = malloc(sizeof(t_have_eat));
		if (!philo[i].nb_h_eat)
			return (1);
		philo[i].nb_h_eat->nb_have_eat = 0;
		i++;
	}
	table->philo = philo;
	return (0);
}

static int	fill_table2(t_table *table, char **av)
{
	if (av[5])
	{
		table->nb_eat->nb_times_must_eat = ft_atol(av[5]);
		if (table->nb_eat->nb_times_must_eat == 0)
		{
			printf("Insuffisant nb each eat must be > 0");
			return (1);
		}
	}
	return (0);
}

static int	fill_table(t_table *table, char **av)
{
	table->nb_philo = ft_atol(av[1]);
	if (table->nb_philo <= 0)
	{
		printf("Insuffisant philo must be > 1");
		return (1);
	}
	table->time_to_die = ft_atol(av[2]);
	if (table->time_to_die == 0)
	{
		printf("Insuffisant time_to_die must be > 0");
		return (1);
	}
	table->time_to_eat = ft_atol(av[3]);
	if (table->time_to_eat == 0)
	{
		printf("Insuffisant time_to_eat must be > 0");
		return (1);
	}
	table->time_to_sleep = ft_atol(av[4]);
	if (fill_table2(table, av))
		return (1);
	return (0);
}

static int	init_table(t_table *table, char **av)
{
	table->nb_eat = malloc(sizeof(t_must_be_eat));
	if (!table->nb_eat)
		return (1);
	table->nb_eat->nb_times_must_eat = 0;
	if (fill_table(table, av))
	{
		free(table->nb_eat);
		return (1);
	}
	table->fork = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->fork)
	{
		free(table->nb_eat);
		return (1);
	}
	table->stoper = malloc(sizeof(t_stop));
	if (!table->stoper)
	{
		free(table->nb_eat);
		free(table->fork);
		return (1);
	}
	table->stoper->stop = 0;
	return (0);
}

int	init(t_table *table, char **av)
{
	if (get_current_time(&table->time_start) == -1)
		return (1);
	if (init_table(table, av))
		return (1);
	if (init_philo(table))
	{
		free_all(table);
		return (1);
	}
	if (init_all_mutex(table))
	{
		free_all(table);
		return (1);
	}
	return (0);
}
