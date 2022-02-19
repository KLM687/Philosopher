/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:57:50 by flee              #+#    #+#             */
/*   Updated: 2022/02/17 10:57:52 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_list *philo)
{
	pthread_mutex_lock(&philo->r_mutex);
	gettimeofday(&philo->stop, NULL);
	if (!philo->dead)
		printf("%d %d has taken a fork\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
	pthread_mutex_lock(philo->l_mutex);
	philo->pos = 0;
	gettimeofday(&philo->stop, NULL);
	if (!philo->dead)
	{
		printf("%d %d has taken a fork\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
		printf("%d %d is eating\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
	}
	gettimeofday(&philo->stop, NULL);
	ft_msleep(philo->eat, philo->start);
	gettimeofday(&philo->start1, NULL);
	philo->pos = 1;
	pthread_mutex_unlock(&philo->r_mutex);
	pthread_mutex_unlock(philo->l_mutex);
}

void	eating1(t_list *philo)
{
	usleep(100);
	pthread_mutex_lock(philo->l_mutex);
	gettimeofday(&philo->stop, NULL);
	if (!philo->dead)
		printf("%d %d has taken a fork\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
	pthread_mutex_lock(&philo->r_mutex);
	philo->pos = 0;
	gettimeofday(&philo->stop, NULL);
	if (!philo->dead)
	{
		printf("%d %d has taken a fork\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
		printf("%d %d is eating\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
	}
	gettimeofday(&philo->stop, NULL);
	ft_msleep(philo->eat, philo->start);
	gettimeofday(&philo->start1, NULL);
	philo->pos = 1;
	pthread_mutex_unlock(philo->l_mutex);
	pthread_mutex_unlock(&philo->r_mutex);
}

void	thinking(t_list *philo)
{
	gettimeofday(&philo->stop, NULL);
	if (!philo->dead)
		printf("%d %d is thinking\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
}

void	sleeping(t_list *philo)
{
	gettimeofday(&philo->stop, NULL);
	if (!philo->dead)
		printf("%d %d is sleeping\n",chrono(philo->start, philo->stop, philo->dif), philo->philo);
	ft_msleep(philo->sleep, philo->start);
}