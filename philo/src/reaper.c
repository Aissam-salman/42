/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:27:41 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:42:11 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static int	reaper_detect_dead(t_table *table, size_t current_time, size_t i)
{
	pthread_mutex_lock(&table->stoper->stop_mutex);
	table->stoper->stop = 1;
	pthread_mutex_unlock(&table->stoper->stop_mutex);
	pthread_mutex_unlock(&table->philo[i].let->last_eat_times_mutex);
	pthread_mutex_lock(&table->print_lock);
	print_action(&table->philo[i], DIED, current_time - table->time_start,
		table->philo[i].index);
	pthread_mutex_unlock(&table->print_lock);
	return (1);
}

static void	*reaper_detect_alleat(t_table *table)
{
	pthread_mutex_lock(&table->stoper->stop_mutex);
	table->stoper->stop = 1;
	pthread_mutex_unlock(&table->stoper->stop_mutex);
	return (NULL);
}

static int	reaper_check_philo(t_table *table, size_t *all_eat)
{
	size_t	current_time;
	size_t	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (get_current_time(&current_time) == -1)
			return (1);
		pthread_mutex_lock(&table->philo[i].let->last_eat_times_mutex);
		if ((current_time
				- table->philo[i].let->last_eat_times) > table->time_to_die)
			return (reaper_detect_dead(table, current_time, i));
		pthread_mutex_unlock(&table->philo[i].let->last_eat_times_mutex);
		pthread_mutex_lock(&table->philo[i].nb_h_eat->nb_have_eat_mutex);
		if (table->nb_eat->nb_times_must_eat > 0)
		{
			if (table->philo[i].nb_h_eat->nb_have_eat
				>= table->nb_eat->nb_times_must_eat)
				*all_eat = *all_eat + 1;
		}
		pthread_mutex_unlock(&table->philo[i].nb_h_eat->nb_have_eat_mutex);
		i++;
	}
	return (0);
}

void	*thread_routine_reaper(void *data)
{
	t_table	*table;
	size_t	all_eat;

	table = (t_table *)data;
	while (1)
	{
		all_eat = 0;
		if (reaper_check_philo(table, &all_eat))
			return (NULL);
		if (table->nb_eat->nb_times_must_eat > 0 && all_eat == table->nb_philo)
			return (reaper_detect_alleat(table));
		usleep(100);
	}
	return (NULL);
}
