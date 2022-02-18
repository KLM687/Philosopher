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

void	*routine0(t_list *philo)
{
	int	i;

	i = 0;
	while (i < philo->occ)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		i++;
	}
	return (0);
}

void	*routine1(t_list *philo)
{
	int	i;

	i = 0;
	while (i < philo->occ)
	{
		sleeping(philo);
		thinking(philo);
		eating1(philo);
		i++;
	}
	return (0);
}

void	*philo_life(void *arg)
{
	t_list	*philo;
	
	philo = (t_list *)arg;
	usleep(500);
	if (philo->start_life == 0)
		routine0(philo);
	else if (philo->start_life == 1)
		routine1(philo);
	return (0);
}