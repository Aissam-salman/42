/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:14:23 by alamjada          #+#    #+#             */
/*   Updated: 2026/03/02 12:37:42 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define TRUE 1
# define FALSE 0

# include <pthread.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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
	pthread_mutex_t	nb_have_eat_mutex;
	size_t			nb_have_eat;
}					t_have_eat;

typedef struct s_philo
{
	size_t			index;
	pthread_t		tid;
	t_have_eat		*nb_h_eat;
	t_let			*let;
	struct s_table	*table;
}					t_philo;

typedef struct s_must_be_eat
{
	pthread_mutex_t	nb_times_must_eat_mutex;
	size_t			nb_times_must_eat;
}					t_must_be_eat;

typedef struct s_table
{
	size_t			nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_start;
	t_must_be_eat	*nb_eat;
	pthread_mutex_t	print_lock;
	t_stop			*stoper;
	pthread_mutex_t	*fork;
	pthread_t		reaper;
	t_philo			*philo;
}					t_table;

// SRC/INIT.C
int					init(t_table *table, char **av);

// SRC/UTILS.C
int					get_current_time(size_t *time);
size_t				get_min(int x, int y);
size_t				get_max(int x, int y);
size_t				ft_atol(char *str);

// SRC/UTILS2.C
int					ft_isdigit(char c);
int					is_valid_params(int ac, char **av);

// SRC/MUTEX.C
int					init_all_mutex(t_table *table);
int					destroy_all_mutex(t_table *table);

// SRC/RUN.C
int					run(t_table *table);

// SRC/PRINT.C
void				print_action(t_philo *philo, t_action action, int time,
						int index);
void				print_params(void);

// SRC/MEMORY.C
void				free_arr(t_philo *philo, size_t nb_philo);
void				free_all(t_table *table);

// SRC/REAPER.C
void				*thread_routine_reaper(void *data);

// SRC/PHILO_ROUTINE.C
void				*thread_routine_philo(void *data);

// SRC/ACTION.C
int					think(t_philo *philo);
int					sleeping(t_philo *philo);
int					eat(t_philo *philo);

#endif
