/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:12:08 by flee              #+#    #+#             */
/*   Updated: 2022/02/28 16:12:11 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list 	*stop_all(t_list *philo)
{
	while (!philo->end)
	{
		philo->end = 1;
		philo = philo->next;
	}
	return (philo);
}

bool	monitoring(t_list *philo)
{
	int		clock;
	struct	timeval stop;
	struct	timeval diff;

	usleep(10000);
	while (1)
	{
		gettimeofday(&stop, NULL);
		pthread_mutex_lock(philo->m_mutex);
		clock =	chrono(philo->clock_start, stop, diff);
		if (clock >= philo->die)
		{
			pthread_mutex_lock(philo->p_mutex);
			printf("%d %d die\n", chrono(philo->start, stop, diff), philo->philo);
			pthread_mutex_unlock(philo->p_mutex);
			stop_all(philo);
		}
		if (philo->end)
		{
			pthread_mutex_unlock(philo->m_mutex);
			break ;
		}
		pthread_mutex_unlock(philo->m_mutex);
		usleep(500);
		philo = philo->next;
	}
	return (0);
}