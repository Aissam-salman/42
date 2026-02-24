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

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

#define TIMES 1000

/////////////////////////////////////// STRUCT PHILO

typedef enum e_action {
	EAT,
	SLEEP,
	THINK,
	TAKE,
	DIED
} t_action;

typedef struct s_stop
{
	pthread_mutex_t stop_mutex;
	int stop;
} t_stop;

typedef struct s_table
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int 	time_start;
	pthread_mutex_t print_lock;
	t_stop  stoper;
	pthread_mutex_t *fork;
} t_table;

typedef struct s_let
{
	pthread_mutex_t last_eat_times_mutex;
	int last_eat_times;
} t_let;


typedef struct s_philo
{
	int tid;
	t_let let;
	t_table *table;
	// ?? state ? t_action
} t_philo;

/////////////////////////////////////// STRUCT PHILO





/*
void *thread_routine(void *data)
{
	pthread_t tid;
	t_counter *counter;
	int i;

	tid = pthread_self();
	counter = (t_counter *)data;

	pthread_mutex_lock(&counter->count_mutex);
	printf("Thread [%ld]: count start: %d\n", tid, counter->count);
	pthread_mutex_unlock(&counter->count_mutex);

	i = 0;
	while (i < TIMES)
	{
		pthread_mutex_lock(&counter->count_mutex);
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
		i++;
	}
	pthread_mutex_lock(&counter->count_mutex);
	printf("Thread [%ld]: count final: %d\n", tid, counter->count);
	pthread_mutex_unlock(&counter->count_mutex);
	return (NULL);
}
*/

void thread_routine_philo(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;

	// loop tant que vivant  eat -> sleep -> think
        //*  Mark last eat TE of philo, if (time current - TE) > time_to_die  ->>>> died
}

void print_action(t_action action, int time, int tid)
{
	if (action == EAT)
		printf("[%d] %d has eat\n", time, tid);
	else if (action == SLEEP)
		printf("[%d] %d  is sleeping\n", time, tid);
	else if (action == THINK)
		printf("[%d] %d is thinking\n", time, tid);
	else if (action == TAKE)
		printf("[%d] %d has take a fork\n", time, tid);
	else if (action == DIED)
		printf("[%d] %d died\n", time, tid);
}

int main(int ac, char **av)
{
	if (ac < 5)
		return (1);
	(void)av;
	struct timeval tv;
	// init_table(ac, av)

	// GET INFO FROM ARGS, 
	// PARSING IT 
	// IF OK
	// CREATE t_table struct,
	// init mutex all
	// create t_philo, N 
	// create thread , usleep pair ,
	// create reaper, check all thread last_eat_times,
	// begin routine 
	
	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error: gettimeofday\n");
		return (1);
	}
	printf("Microseconds: %ld\n", tv.tv_usec);

	// counter.count = 0;
	// pthread_mutex_init(&counter.count_mutex, NULL);
	// printf("Res attendu: %d\n", TIMES * 2);
	// pthread_create(&tid1, NULL, thread_routine, &counter);
	// printf("First thread [%ld] created\n", tid1);
	// pthread_create(&tid2, NULL, thread_routine, &counter);
	// printf("Second thread [%ld] created\n", tid2);
	// pthread_join(tid1, NULL);
	// printf("Union first thread [%ld]\n", tid1);
	// pthread_join(tid2, NULL);
	// printf("Union second thread [%ld]\n", tid2);
	// if (counter.count == TIMES * 2)
	// 	printf("OK, greet: %d\n", counter.count);
	// else
	// 	printf("Noooo, res: %d\n", counter.count);
	// pthread_mutex_destroy(&counter.count_mutex);
	return (0);
}


/*
// cc -pthread -fsanitize=thread -g  (contre data race)
 *  1 seconds = 1000
 *  1000 microseconds = 1 milliseconds   formula / 1000  usleep(1 * 1000) for 1 mls
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
