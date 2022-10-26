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

int	routine(t_list *philo)
{
	while (1)
	{
		if (!eat(philo))
			return (1);
		sleep_think(philo);
		pthread_mutex_lock(philo->m_mutex);
		if (philo->end)
		{
			pthread_mutex_unlock(philo->m_mutex);
			return (1);
		}
		pthread_mutex_unlock(philo->m_mutex);
		if (philo->occ != 0)
		{
			philo->eating++;
			if (philo->eating == philo->occ)
				return (0);
		}	
	}
	return (1);
}

int	routine1(t_list *philo)
{
	usleep(500);
	while (1)
	{
		if (!eat1(philo))
			return (1);
		sleep_think(philo);
		pthread_mutex_lock(philo->m_mutex);
		if (philo->end)
		{
			pthread_mutex_unlock(philo->m_mutex);
			return (1);
		}
		pthread_mutex_unlock(philo->m_mutex);
		if (philo->occ != 0)
		{
			philo->eating++;
			if (philo->eating == philo->occ)
				return (0);
		}
	}
	return (1);
}

void	*philo_life(void *arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	philo->clock_start = philo->start;
	if ((philo->philo % 2) == 0)
		routine(philo);
	else
		routine1(philo);
	pthread_mutex_lock(philo->m_mutex);
	philo->end = 1;
	pthread_mutex_unlock(philo->m_mutex);
	return (0);
}
