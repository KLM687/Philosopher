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

t_list	*create_mutex(char **argv, t_list *philo, pthread_mutex_t *p_mutex, pthread_mutex_t *m_mutex)
{
	int	i;
	int	nb_philo;

	i = -1;
	nb_philo = ft_atoi(argv[1]);
	while (++i < nb_philo)
	{
		pthread_mutex_init(&philo->r_mutex, NULL);
		philo->next->l_mutex = &philo->r_mutex;
		philo->p_mutex = p_mutex;
		philo->m_mutex = m_mutex;
		philo = philo->next;
	}
	return (philo);
}

