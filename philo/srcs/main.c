/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:39:53 by flee              #+#    #+#             */
/*   Updated: 2022/02/09 09:39:54 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex;

int	parse(int argc, char **argv)
{
	if (argc != 6)
		return (0);
	if (ft_atoi(argv[1]) < 3 && !ft_isdigit(argv[1]))
		return (0);
	if (ft_atoi(argv[2]) <= 0 && !ft_isdigit(argv[2]))
		return (0);
	if (ft_atoi(argv[3]) <= 0 && !ft_isdigit(argv[3]))
		return (0);
	if (ft_atoi(argv[4]) <= 0 && !ft_isdigit(argv[4]))
		return (0);
	if (ft_atoi(argv[5]) <= 0 && !ft_isdigit(argv[5]))
		return (0);
	return (1);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*memory;

	tmp = *lst;
	while (tmp)
	{
		memory = tmp->next;
		tmp->next = NULL;
		tmp->previous = NULL;
		free(tmp);
		tmp = memory;
	}
	*lst = NULL;
}

int main(int argc, char **argv)
{
    t_list	*philo;

	philo = NULL;
    if (!parse(argc, argv))
    {
        printf("error in argument\n");
        return (0);
    }
    philo = create_list(argv, philo);
	philo = create_mutex(argv, philo);
	//start_thread(philo, ft_atoi(argv[1]));
	//ft_lstclear(&philo);
	return (0);
}
