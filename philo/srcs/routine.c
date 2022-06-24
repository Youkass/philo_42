/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:24:59 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/24 15:37:31 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	if (ft_take_fork(philo))
		return (ft_print_state(philo, "is dead"), NULL);
	ft_spleep(philo);
	ft_think(philo);
	return (NULL);
}

int	ft_while_odd(t_data *data)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (i < data->nb_of)
	{
		if (!(i % 2))
		{
			tmp = &(data->philo[i]);
			if (pthread_create(&(data->philo[i]->thread_id), NULL, &ft_routine, tmp))
				return (1);
		}
		++i;
	}
}

int	ft_while_per(t_data *data)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (i < data->nb_of)
	{
		if (i % 2)
		{
			tmp = &(data->philo[i]);
			if (pthread_create(&(data->philo[i]->thread_id), NULL, &ft_routine, tmp))
				return (1);
		}
		++i;
	}
}

int	ft_while(t_data *data)
{
	if (ft_while_odd(data))
		return (1);
	if (ft_while_per(data))
		return (1);
	return (0);
}

int	ft_philo_dead(t_data *data)
{
	int	i;

	i = -1
	while (i++ < data->nb_of)
	{
		if (data->philo[i]->is_dead)
			return (1);
	}
	return (0);
}

int	ft_create_philo(t_data *data)
{
	int		i;
	t_philo	*tmp;

	if (data.nb_to_eat > 0)
	{
		i = -1;
		while (i++ < data->nb_to_eat && !data->is_dead)
			ft_while(data);
		if (data->is_dead)
			return (1);
	}
	else
	{
		while (!ft_philo_dead(data))
			ft_while(data);
		if (data->is_dead)
			return (1);
	}
	return (0);
}
