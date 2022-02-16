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

void	*philo_life(void *arg)
{
	t_list	*philo;
	int		i;
	
	philo = (t_list *)arg;
	i = 0;
	//gettimeofday(&philo->stop, NULL);
	//printf("%d %d philo is starting\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
	while (i < philo->occ)
	{
		pthread_mutex_lock(philo->r_mutex);
		pthread_mutex_lock(philo->l_mutex);
		gettimeofday(&philo->stop, NULL);
		printf("%d %d philo start eating\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
		ft_msleep(philo->eat, philo->start);
		pthread_mutex_unlock(philo->r_mutex);
		pthread_mutex_unlock(philo->l_mutex);
		gettimeofday(&philo->stop, NULL);
		printf("%d %d philo finish eating\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
		i++;
	}
	printf("%d %d philo is leaving\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
	return (0);
}