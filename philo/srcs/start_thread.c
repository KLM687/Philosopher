/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:33:20 by flee              #+#    #+#             */
/*   Updated: 2022/02/13 14:33:21 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	synch_time(t_list *philo, int nb_philo)
{
	int	i;
	struct timeval origin_start;

	i = 0;
	gettimeofday(&origin_start, NULL);
	while (i < nb_philo)
	{
		philo->start = origin_start;
		philo = philo->next;
		i++;
	}
}

bool	launch_thread(pthread_t *tmp_thread, t_list *philo, int nb_philo)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (i < nb_philo)
	{
		if ((philo->philo % 2) == 0)
			pthread_create(tmp_thread + c++, NULL, &philo_life, philo);
		philo = philo->next;
		i++;
		
	}
	i = 0;
	while (i < nb_philo)
	{
		if ((philo->philo % 2) != 0)
			pthread_create(tmp_thread + c++, NULL, &philo_life, philo);
		philo = philo->next;
		i++;
	}
	return (1);
}

void	start_thread(t_list *philo, int nb_philo)
{
	int				i;
	pthread_t 		*tmp_thread;

	i = 0;
	tmp_thread = malloc(sizeof(pthread_t) * nb_philo);
	memset(tmp_thread, 0, nb_philo + 1);
	synch_time(philo, nb_philo);
	if (launch_thread(tmp_thread, philo, nb_philo))
	{
		while (i < nb_philo)
		{
			pthread_join(tmp_thread[i], NULL);
			i++;
		}
	}
	free(tmp_thread);
}