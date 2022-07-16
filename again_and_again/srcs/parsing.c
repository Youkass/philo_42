/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:09:23 by yobougre          #+#    #+#             */
/*   Updated: 2022/07/16 14:00:58 by yobougre         ###   ########.fr       */
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
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		++i;
	}
	return (0);
}

int	ft_assign_fork(t_data *data)
{
	int	i;

	i = 1;
	if (ft_init_mutex(data))
		return (1);
	data->philo[0].l_fork = &(data->forks[data->nb_of - 1]);
	data->philo[0].r_fork = &(data->forks[0]);
	while (i < data->nb_of)
	{
		data->philo[i].l_fork = &(data->forks[i - 1]);
		data->philo[i].r_fork = &(data->forks[i]);
		++i;
	}
	return (0);
}

int	ft_create_philo(t_data *data)
{
	int		i;

	if (data->nb_to_eat > 0)
	{
		i = -1;
		while (i++ < data->nb_to_eat && !data->is_dead)
		{
			if (ft_while(data))
				return (1);
		}
		if (data->is_dead)
			return (1);
	}
	else
	{
		while (!ft_philo_dead(data))
		{
			if (ft_while(data))
				return (1);
		}
		if (data->is_dead)
			return (1);
	}
	return (0);
}
