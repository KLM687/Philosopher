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
				philo->dead = 1;
				printf("%d %d die\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
				return (0);
			}
		}
		philo = philo->next;
	}
	return (0);
}