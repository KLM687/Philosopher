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

t_list	*ft_thread_mutex(t_list *philo, int nb_philo, pthread_mutex_t thread_mutex)
{
	int	i;

	i = -1;
	while (++i < nb_philo)
	{
		philo->global_mutex = &thread_mutex;
		philo = philo->next;
	}
	return (philo);
}

t_list	*create_mutex(char **argv, t_list *philo)
{
	int	i;
	int	start;
	int	nb_philo;

	i = -1;
	start = 0;
	nb_philo = ft_atoi(argv[1]);
	while (++i < nb_philo)
	{
		if (start == 3)
			start = 0;
		pthread_mutex_init(&philo->r_mutex, NULL);
		philo->start_life = start;
		philo->next->l_mutex = &philo->r_mutex;
		philo = philo->next;
		start++;
	}
	return (philo);
}

