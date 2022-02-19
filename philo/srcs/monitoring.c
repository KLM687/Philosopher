/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:49:17 by flee              #+#    #+#             */
/*   Updated: 2022/02/19 10:49:18 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_dead(t_list *philo)
{
	while (philo->dead == 0)
	{
		philo->dead = 1;
		philo = philo->next;
	}
}

void	*monitoring(void *arg)
{
	t_list	*philo;
	struct	timeval stop1;
	struct	timeval diff1;

	philo = (t_list *)arg;
	ft_msleep(10, philo->start);
	while (!philo->dead)
	{
		if (philo->pos == 1 && !philo->finish)
		{
			gettimeofday(&stop1, NULL);
			philo->time = chrono(philo->start1, stop1, diff1);
			if (philo->time >= philo->die)
			{
				fill_dead(philo);
				gettimeofday(&philo->stop, NULL);
				printf("%d %d %d die\n",chrono(philo->start, philo->stop, philo->dif),chrono(philo->start1, stop1, diff1), philo->philo);
				return (0);
			}
		}
		philo = philo->next;
	}
	return (0);
}