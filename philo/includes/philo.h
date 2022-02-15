/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:40:25 by flee              #+#    #+#             */
/*   Updated: 2022/02/09 09:40:26 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_list
{
    int				philo;
    int				fork;
	int				die;
	int				eat;
	int				sleep;
	int				occ;
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	r_mutex;
	pthread_mutex_t	l_mutex;
	struct timeval	start;
    struct s_list 	*next;
    struct s_list 	*previous;
}   t_list;

t_list	*create_list(char **argv, t_list *philo);
int		ft_atoi(const char *str);
void	start_thread(t_list *philo, int nb_philo);
void 	ft_msleep(int ms, struct timeval start);
int		chrono(struct timeval start, struct timeval stop, struct timeval diff);
t_list	*create_mutex(char **argv, t_list *philo);

#endif
