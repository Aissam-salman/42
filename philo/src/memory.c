/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:26:25 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:40:58 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	free_arr(t_philo *philo, size_t nb_philo)
{
	size_t	i;

	if (!philo)
		return ;
	i = 0;
	while (i < nb_philo)
	{
		if (philo && philo[i].nb_h_eat)
			free(philo[i].nb_h_eat);
		if (philo && philo[i].let)
			free(philo[i].let);
		i++;
	}
	free(philo);
}

void	free_all(t_table *table)
{
	if (!table)
		return ;
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
