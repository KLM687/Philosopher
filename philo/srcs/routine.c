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

bool	eat(t_list *philo)
{
	pthread_mutex_lock(&philo->r_mutex);
	ft_print("has taken a fork", philo, 1);
	pthread_mutex_lock(philo->l_mutex);
	ft_print("has taken a fork", philo, 2);
	ft_msleep(philo->eat, philo->start);
	pthread_mutex_unlock(&philo->r_mutex);
	pthread_mutex_unlock(philo->l_mutex);
	return (1);
}

bool	eat1(t_list *philo)
{
	usleep(500);
	pthread_mutex_lock(philo->l_mutex);
	ft_print("has taken a fork", philo, 1);
	pthread_mutex_lock(&philo->r_mutex);
	ft_print("has taken a fork", philo, 2);
	ft_msleep(philo->eat, philo->start);
	pthread_mutex_unlock(philo->l_mutex);
	pthread_mutex_unlock(&philo->r_mutex);
	return (1);
}

void	sleep_think(t_list *philo)
{
	gettimeofday(&philo->stop, NULL);
	ft_print("is sleeping", philo, 1);
	ft_msleep(philo->sleep, philo->start);
	gettimeofday(&philo->stop, NULL);
	ft_print("is thinking", philo, 1);
}
