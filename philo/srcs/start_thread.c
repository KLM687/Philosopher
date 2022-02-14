/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:33:20 by flee              #+#    #+#             */
/*   Updated: 2022/02/13 14:33:21 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_life(void *arg)
{
	t_list			*philo;
	int				i;

	philo = (t_list *)arg;
	i = 0;
	printf("philo %d\n",philo->philo);
	printf("%d  %d\n",philo->next->fork, philo->previous->fork);
	while (i < 2)
	{
		if (philo->next->fork == 1 && philo->previous->fork == 1)
		{
			philo->next->fork = 0;
 			philo->previous->fork = 0;
			printf("philo %d is eating\n", philo->philo);
			sleep(1);
			philo->next->fork = 1;
			philo->previous->fork = 1;
			i++;
		}
		else
			printf("thinking\n");
		sleep(3);
	}
	printf("philo %d is leaving\n", philo->philo);
	return (0);
}

void	start_thread(t_list *philo, int nb_philo)
{
	int			i;
	pthread_t 	*thread;

	i = -1;
	thread = malloc(sizeof(pthread_t) * nb_philo);
	memset(thread, 0, nb_philo + 1);
	while (++i < nb_philo)
	{
		pthread_create(thread + i, NULL, &philo_life, philo);
		philo = philo->next;
	}
	i = -1;
	while (++i < nb_philo + 1)
		pthread_join(thread[i], NULL);
}