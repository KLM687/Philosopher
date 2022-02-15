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
	while (i < 1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (philo->next->fork == 1 && philo->previous->fork == 1)
		{
			printf("philo %d\n",philo->philo);
			printf("%d  %d\n",philo->next->fork, philo->previous->fork);
			philo->next->fork = 0;
 			philo->previous->fork = 0;
			printf("philo %d is eating\n", philo->philo);
			ft_msleep(500, philo->start);
			philo->next->fork = 1;
			philo->previous->fork = 1;
			i++;
			printf("philo %d stop eating\n", philo->philo);
		}
		pthread_mutex_unlock(&philo->mutex);
		ft_msleep(1000, philo->start);
	}
	printf("philo %d is leaving\n", philo->philo);
	return (0);
}

void	start_thread(t_list *philo, int nb_philo)
{
	int				i;
	pthread_t 		*tmp_thread;
	pthread_mutex_t	tmp_mutex;
	struct timeval	tmp_start;

	i = -1;
	tmp_thread = malloc(sizeof(pthread_t) * nb_philo);
	memset(tmp_thread, 0, nb_philo + 1);
	gettimeofday(&tmp_start, NULL);
	pthread_mutex_init(&tmp_mutex, NULL);
	while (++i < nb_philo)
	{
		philo->start = tmp_start;
		philo->mutex = tmp_mutex;
		pthread_create(tmp_thread + i, NULL, &philo_life, philo);
		philo = philo->next;
	}
	i = -1;
	while (++i < nb_philo)
		pthread_join(tmp_thread[i], NULL);
}