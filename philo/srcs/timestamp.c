/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:22:27 by flee              #+#    #+#             */
/*   Updated: 2022/02/14 09:22:29 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	chrono(struct timeval start, struct timeval stop, struct timeval diff)
{
	diff.tv_usec = stop.tv_usec - start.tv_usec;
	diff.tv_sec = stop.tv_sec - start.tv_sec;
	diff.tv_sec *= 1000;
	diff.tv_usec /= 1000;
	return (diff.tv_usec + diff.tv_sec);
}

void	ft_msleep(int ms, struct timeval start)
{
	struct timeval	stop;
	struct timeval	diff;
	size_t			begin;
	size_t			end;

	gettimeofday(&stop, NULL);
	begin = chrono(start, stop, diff);
	end = begin + ms;
	while (begin < end)
	{
		usleep(100);
		gettimeofday(&stop, NULL);
		begin = chrono(start, stop, diff);
	}
}
