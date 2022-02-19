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
		if ((i + 1) < philo->occ)
			philo->finish = 1;
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
		eating1(philo);
		if ((i + 1) < philo->occ)
			philo->finish = 1;
		sleeping(philo);
		thinking(philo);
		i++;
	}
	return (0);
}

void	*philo_life(void *arg)
{
	t_list	*philo;
	
	philo = (t_list *)arg;
	philo->pos = 1;
	gettimeofday(&philo->start1, NULL);
	if (philo->start_life == 0)
		routine0(philo);
	else if (philo->start_life == 1)
		routine1(philo);
	return (0);
}