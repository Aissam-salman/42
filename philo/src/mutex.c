/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:20:43 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:39:02 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	init_all_mutex(t_table *table)
{
	size_t	i;
	t_philo	*philos;

	philos = table->philo;
	if (pthread_mutex_init(&table->stoper->stop_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->nb_eat->nb_times_must_eat_mutex, NULL) != 0)
		return (1);
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->fork[i], NULL) != 0)
			return (1);
		if (pthread_mutex_init(&philos[i].let->last_eat_times_mutex, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&philos[i].nb_h_eat->nb_have_eat_mutex,
				NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	destroy_all_mutex(t_table *table)
{
	size_t	i;
	t_philo	*philos;

	philos = table->philo;
	if (pthread_mutex_destroy(&table->stoper->stop_mutex) != 0)
		return (1);
	if (pthread_mutex_destroy(&table->print_lock) != 0)
		return (1);
	if (pthread_mutex_destroy(&table->nb_eat->nb_times_must_eat_mutex) != 0)
		return (1);
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_destroy(&table->fork[i]) != 0)
			return (1);
		if (pthread_mutex_destroy(&philos[i].let->last_eat_times_mutex) != 0)
			return (1);
		if (pthread_mutex_destroy(&philos[i].nb_h_eat->nb_have_eat_mutex) != 0)
			return (1);
		i++;
	}
	return (0);
}
