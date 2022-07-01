/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:36:28 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/30 13:51:25 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of);
	if (!data->forks)
		return (1);
	while (i < data->nb_of)
	{
		if (pthread_mutex_init(&(data->forks[i])))
			return (1);
		++i;
	}
	return (0);
}

void	ft_assign_fork(t_data *data)
{
	int	i;

	i = 1;
	data->philo[0]->l_fork = &(data->forks[nb_of - 1]);
	data->philo[0]->r_fork = &(data->forks[0]);
	while (i < data->nb_of)
	{
		data->philo[i]->l_fork = &(data->forks[i - 1]);
		data->philo[i]->r_fork = &(data->forks[i]);
		++i;
	}
}
