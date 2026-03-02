/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:22:23 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:39:32 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	join_all(t_table *table)
{
	size_t	i;
	t_philo	*philo;

	philo = table->philo;
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(philo[i].tid, NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_join(table->reaper, NULL) != 0)
		return (1);
	return (0);
}

static int	run_thread(t_table *table)
{
	size_t	i;
	t_philo	*philos;

	philos = table->philo;
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_create(&(philos[i].tid), NULL, thread_routine_philo,
				(void *)&philos[i]) != 0)
			return (1);
		if (i % 2 == 0)
			if (usleep(500) == -1)
				return (1);
		i++;
	}
	if (pthread_create(&table->reaper, NULL, thread_routine_reaper,
			(void *)table) != 0)
		return (1);
	return (0);
}

int	run(t_table *table)
{
	if (run_thread(table))
		return (1);
	if (join_all(table))
		return (1);
	if (destroy_all_mutex(table))
		return (1);
	return (0);
}
