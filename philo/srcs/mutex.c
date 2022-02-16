/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:53:07 by flee              #+#    #+#             */
/*   Updated: 2022/02/15 11:53:08 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*create_mutex(char **argv, t_list *philo)
{
	int	i;
	int	nb_philo;

	i = -1;
	nb_philo = ft_atoi(argv[1]);
	while (++i < nb_philo)
	{
		pthread_mutex_init(&philo->fork_mutex, NULL);
		philo = philo->next;
	}
	i = -1;
	while (++i < nb_philo)
	{
		philo->l_mutex = &philo->previous->fork_mutex;
		philo->r_mutex = &philo->next->fork_mutex;
		philo = philo->next;
	}
	return (philo);
}

