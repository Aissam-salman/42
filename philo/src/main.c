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
#include <pthread.h>

#define TIMES 1000

// cc -pthread -fsanitize=thread -g  (contre data race)
typedef struct s_counter {
	pthread_mutex_t count_mutex;
	int count;
} t_counter;

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

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	pthread_t tid1;
	pthread_t tid2;
	t_counter counter;

	counter.count = 0;
	pthread_mutex_init(&counter.count_mutex, NULL);
	printf("Res attendu: %d\n", TIMES * 2);
	pthread_create(&tid1, NULL, thread_routine, &counter);
	printf("First thread [%ld] created\n", tid1);
	pthread_create(&tid2, NULL, thread_routine, &counter);
	printf("Second thread [%ld] created\n", tid2);
	pthread_join(tid1, NULL);
	printf("Union first thread [%ld]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Union second thread [%ld]\n", tid2);
	if (counter.count == TIMES * 2)
		printf("OK, greet: %d\n", counter.count);
	else
		printf("Noooo, res: %d\n", counter.count);
	pthread_mutex_destroy(&counter.count_mutex);
	return (0);
}
