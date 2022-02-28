/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:52:42 by flee              #+#    #+#             */
/*   Updated: 2022/02/09 09:52:43 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_print(char *str, t_list *philo, int p)
{
	int	time;

	gettimeofday(&philo->stop, NULL);
	time = chrono(philo->start, philo->stop, philo->dif);
	pthread_mutex_lock(philo->m_mutex);
	if (philo->end)
	{
		pthread_mutex_unlock(philo->m_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->m_mutex);
	pthread_mutex_lock(philo->p_mutex);
	printf("%d %d %s\n", time, philo->philo, str);
	if (p == 2)
	{
		printf("%d %d %s\n", time, philo->philo, "is eating");
		pthread_mutex_lock(philo->m_mutex);
		gettimeofday(&philo->clock_start, NULL);
		pthread_mutex_unlock(philo->m_mutex);
	}
	pthread_mutex_unlock(philo->p_mutex);
	return (1);
}

bool 	ft_isdigit(char *str)
{
	int	i;
	int c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < '0' || c > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	result;
	long int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((long)(result * sign));
}	
