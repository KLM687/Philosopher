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

void	*check_death(void *arg)
{
	int			death;
	t_list		*philo;
	
	philo = (t_list *)arg;
	struct timeval begin;
	struct timeval stop;
	struct timeval dif;

	gettimeofday(&begin, NULL);
	death = 0;
	while (death < philo->die)
	{
		if (philo->end == 1)
			return (0);
		else if (philo->eating == 0)
			death = 0;
		else 
		{
			gettimeofday(&stop, NULL);
			death = chrono(begin, stop, dif);
			if (death >= philo->die)
			{
				gettimeofday(&philo->stop, NULL);
				printf("%d %d died\n",chrono(philo->start, philo->stop, dif), philo->philo);
				philo->death->death = 1;
			}
		}
		usleep(100); 
	}
	return (0);
}

void	*routine0(t_list *philo)
{
	pthread_t	death_thread;
	int			i;

	i = 0;
	pthread_create(&death_thread, NULL, &check_death, philo);
	pthread_detach(death_thread);
	while (i <= philo->occ && !philo->death->death)
	{
		eating(philo);
		if (!philo->death->death)
			sleeping(philo);
		if (!philo->death->death)
			thinking(philo);
		i++;
		if (philo->occ == 0)
			i = 0;
	}
	philo->end = 1;
	usleep(200);
	return (0);
}

void	*routine1(t_list *philo)
{
	pthread_t	death_thread;
	int			i;

	i = 0;
	pthread_create(&death_thread, NULL, &check_death, philo);
	pthread_detach(death_thread);
	while (i <= philo->occ && !philo->death->death)
	{
		eating1(philo);
		if (!philo->death->death)
			sleeping(philo);
		if (!philo->death->death)
			thinking(philo);
		i++;
		if (philo->occ == 0)
			i = 0;
	}
	philo->end = 1;
	usleep(200);
	return (0);
}

void	*philo_life(void *arg)
{
	t_list		*philo;
	
	philo = (t_list *)arg;
	if ((philo->philo % 2) == 0)
		routine0(philo);
	else
		routine1(philo);
	return (0);
}