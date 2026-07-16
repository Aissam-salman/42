/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:25:08 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:40:45 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	print_params(void)
{
	printf("Error params.\n");
	printf("./philo number_of_philosophers time_to_die");
	printf(" time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n ");
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
		printf("[%d] %d is sleeping\n", time, index + 1);
	else if (action == THINK)
		printf("[%d] %d is thinking\n", time, index + 1);
	else if (action == TAKE)
		printf("[%d] %d has take a fork\n", time, index + 1);
	else if (action == DIED)
		printf("[%d] %d died\n", time, index + 1);
}
