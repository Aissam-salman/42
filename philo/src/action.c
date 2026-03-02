/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:30:59 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:42:49 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static void	eat_core(t_philo *philo, size_t current_time)
{
	pthread_mutex_lock(&philo->table->print_lock);
	print_action(philo, TAKE, current_time - philo->table->time_start,
		philo->index);
	pthread_mutex_unlock(&philo->table->print_lock);
	pthread_mutex_lock(&philo->table->print_lock);
	print_action(philo, EAT, current_time - philo->table->time_start,
		philo->index);
	pthread_mutex_unlock(&philo->table->print_lock);
	pthread_mutex_lock(&philo->nb_h_eat->nb_have_eat_mutex);
	philo->nb_h_eat->nb_have_eat++;
	pthread_mutex_unlock(&philo->nb_h_eat->nb_have_eat_mutex);
}

int	eat(t_philo *philo)
{
	size_t	current_time;
	size_t	min;
	size_t	max;

	if (get_current_time(&current_time) == -1)
		return (1);
	min = get_min(philo->index, (philo->index + 1) % philo->table->nb_philo);
	max = get_max(philo->index, (philo->index + 1) % philo->table->nb_philo);
	pthread_mutex_lock(&philo->table->fork[min]);
	pthread_mutex_lock(&philo->table->print_lock);
	print_action(philo, TAKE, current_time - philo->table->time_start,
		philo->index);
	pthread_mutex_unlock(&philo->table->print_lock);
	pthread_mutex_lock(&philo->table->fork[max]);
	eat_core(philo, current_time);
	if (get_current_time(&current_time) == -1)
		return (1);
	pthread_mutex_lock(&philo->let->last_eat_times_mutex);
	philo->let->last_eat_times = current_time;
	pthread_mutex_unlock(&philo->let->last_eat_times_mutex);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->table->fork[min]);
	pthread_mutex_unlock(&philo->table->fork[max]);
	return (0);
}

int	sleeping(t_philo *philo)
{
	size_t	current_time;

	pthread_mutex_lock(&philo->table->stoper->stop_mutex);
	if (philo->table->stoper->stop == 1)
	{
		pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
	if (get_current_time(&current_time) == -1)
		return (1);
	pthread_mutex_lock(&philo->table->print_lock);
	print_action(philo, SLEEP, current_time - philo->table->time_start,
		philo->index);
	pthread_mutex_unlock(&philo->table->print_lock);
	usleep(philo->table->time_to_sleep * 1000);
	return (0);
}

int	think(t_philo *philo)
{
	size_t	current_time;

	pthread_mutex_lock(&philo->table->stoper->stop_mutex);
	if (philo->table->stoper->stop == 1)
	{
		pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->stoper->stop_mutex);
	if (get_current_time(&current_time) == -1)
		return (1);
	pthread_mutex_lock(&philo->table->print_lock);
	print_action(philo, THINK, current_time - philo->table->time_start,
		philo->index);
	pthread_mutex_unlock(&philo->table->print_lock);
	usleep(500);
	return (0);
}
