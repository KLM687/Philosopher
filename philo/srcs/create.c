/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:37:34 by flee              #+#    #+#             */
/*   Updated: 2022/02/09 11:37:35 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
		return (lst);
	}
	else
		return (NULL);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		new->previous = tmp;
		tmp->next = new;
	}
	else
		*alst = new;
}

t_list	*ft_lstnew(int content, char **argv)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list) * 1);
	if (tmp == NULL)
		return (0);
	if (tmp)
	{
		tmp->philo = content;
		tmp->fork = 1;
		tmp->die = ft_atoi(argv[2]);
		tmp->eat = ft_atoi(argv[3]);
		tmp->sleep = ft_atoi(argv[4]);
		tmp->occ = ft_atoi(argv[5]);
		tmp->next = NULL;
		tmp->previous = NULL;
	}
	return (tmp);
}

t_list *create_list(char **argv, t_list *philo)
{
	int		i;
	int		count;
	t_list	*tmp;

	i = 0;
	count = ft_atoi(argv[1]);
	while (i < count)
	{
		ft_lstadd_back(&philo, ft_lstnew(i, argv));
		i++;
	}
	tmp = philo;
	philo->previous = ft_lstlast(philo);
	philo = philo->previous;
	philo->next = tmp;
	return (philo);
}