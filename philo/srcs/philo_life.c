/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:33:00 by flee              #+#    #+#             */
/*   Updated: 2022/02/16 14:33:01 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list 	*stop_all(t_list *philo)
{
	while (!philo->dead)
	{
		philo->dead = 1;
		philo = philo->next;
	}
	return (philo);
}

void	*check_death(void *arg)
{
	int			time;
	t_list		*philo;
	
	philo = (t_list *)arg;
	struct timeval begin;
	struct timeval stop;
	struct timeval dif;
	begin = philo->start;
	time = 0;
	pthread_mutex_lock(&philo->local_mutex);
	while(!philo->end)
	{
		while (!philo->eating)
		{
			gettimeofday(&stop, NULL);
			pthread_mutex_unlock(&philo->local_mutex);
			time = chrono(begin, stop, dif);
			if (time >= philo->die)
			{
				pthread_mutex_lock(philo->p_mutex);
				printf("%d %d die\n", philo->philo, chrono(philo->start, philo->stop, philo->dif));
				philo = stop_all(philo);
				pthread_mutex_unlock(philo->p_mutex);
				return (0);
			}
			usleep (500);
			pthread_mutex_lock(&philo->local_mutex);
		}
		gettimeofday(&begin, NULL);
	}
	pthread_mutex_unlock(&philo->local_mutex);
	return (0);
}

int	routine(t_list *philo)
{
	//pthread_t	death_thread;
	int			i;

	i = 0;
	//pthread_create(&death_thread, NULL, &check_death, philo);
	//pthread_detach(death_thread);
	while (i <= philo->occ)
	{
		if (!eat(philo))
			return (0);
		//if (!sleep_think(philo))
		//	return (0);
		i++;
		if (philo->occ == 0)
			i = -1;
	}
	//pthread_mutex_lock(&philo->local_mutex);
	//philo->end = 1;
	//pthread_mutex_lock(&philo->local_mutex);
	return (1);
}

void	*philo_life(void *arg)
{
	t_list		*philo;
	
	philo = (t_list *)arg;
	philo->end = 0;
	if ((philo->philo % 2) == 0)
		usleep(100);
	routine(philo);
	//pthread_mutex_lock(&philo->local_mutex);
	//philo->end = 1;
	//pthread_mutex_lock(&philo->local_mutex);
	//usleep(1000);
	return (0);
}