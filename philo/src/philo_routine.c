/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:30:16 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:42:40 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static int	is_routine_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->stoper->stop_mutex);
	if (philo->table->stoper->stop == 1)
	{
		pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
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
		if (is_routine_stop(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
		if (is_routine_stop(philo))
			return (NULL);
		if (think(philo))
			return (NULL);
		if (is_routine_stop(philo))
			return (NULL);
	}
	return (NULL);
}
