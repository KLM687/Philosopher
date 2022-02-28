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
	pthread_mutex_lock(philo->p_mutex);	
	if (!ft_print("has taken a fork", philo, 1))
		return (0);
	pthread_mutex_unlock(philo->p_mutex);
	pthread_mutex_lock(philo->l_mutex);
	/*pthread_mutex_lock(&philo->local_mutex);
	philo->eating = 1;
	pthread_mutex_unlock(&philo->local_mutex);*/
	pthread_mutex_lock(philo->p_mutex);
	if(!ft_print("has taken a fork", philo, 2))
		return (0);
	pthread_mutex_unlock(philo->p_mutex);
	ft_msleep(philo->eat, philo->start);
	/*pthread_mutex_lock(&philo->local_mutex);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->local_mutex);*/
	pthread_mutex_unlock(&philo->r_mutex);
	pthread_mutex_unlock(philo->l_mutex);
	return (1);
}

bool	sleep_think(t_list *philo)
{
	gettimeofday(&philo->stop, NULL);
	pthread_mutex_lock(philo->p_mutex);
	if(!ft_print("is sleeping", philo, 1))
		return (0);
	pthread_mutex_unlock(philo->p_mutex);
	ft_msleep(philo->sleep, philo->start);
	gettimeofday(&philo->stop, NULL);
	pthread_mutex_lock(philo->p_mutex);
	if (!ft_print("is thinking", philo, 1))
		return (0);
	pthread_mutex_unlock(philo->p_mutex);
	return (1);
}