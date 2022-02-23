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
	if (argc != 6 && argc != 5)
		return (0);
	if (ft_atoi(argv[1]) <= 0 || !ft_isdigit(argv[1]))
		return (0);
	if (ft_atoi(argv[2]) <= 0 || !ft_isdigit(argv[2]))
		return (0);
	if (ft_atoi(argv[3]) <= 0 || !ft_isdigit(argv[3]))
		return (0);
	if (ft_atoi(argv[4]) <= 0 || !ft_isdigit(argv[4]))
		return (0);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0 || !ft_isdigit(argv[5]))
			return (0);
	}
	return (1);
}

void	ft_lstclear(t_list *lst, int nb_philo)
{
	t_list *tmp;
	int i;

	i = 0;
	while (i < nb_philo)
	{
		tmp = lst->next;
		lst->next = NULL;
		lst->previous = NULL;
		free(lst);
		lst = tmp;
		i++;
	}
}

int main(int argc, char **argv)
{
    t_list	*philo;
	t_death	*death;

	philo = NULL;
	death = malloc(sizeof(t_death) * 1);
	death->death = 0;
    if (!parse(argc, argv))
    {
        printf("error in argument\n");
        return (0);
    }
    philo = create_list(argc, argv, philo, death);
	philo = create_mutex(argv, philo);
	start_thread(philo, ft_atoi(argv[1]));
	ft_lstclear(philo, ft_atoi(argv[1]));
	free(death);
	return (0);
}
