/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:08:36 by yobougre          #+#    #+#             */
/*   Updated: 2022/07/21 11:49:11 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	if (ft_eat(philo))
		return (NULL);
	ft_sleep(philo);
	ft_print_state(philo, "is thinking");
	return (NULL);
}

int	ft_while_odd(t_data *data)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (i < data->nb_of)
	{
		if (i % 2 != 0)
		{
			tmp = &(data->philo[i]);
			if (pthread_create(&(data->philo[i].thread_id), NULL, &ft_routine, tmp))
				return (1);
			if (data->is_dead)
				return (1);
		}
		++i;
	}
	return (0);
}

int	ft_while_per(t_data *data)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (i < data->nb_of)
	{
		if (i % 2 == 0)
		{
			tmp = &(data->philo[i]);
			if (pthread_create(&(data->philo[i].thread_id), NULL, &ft_routine, tmp))
				return (1);
			if (data->is_dead)
				return (1);
		}
		++i;
	}
	return (0);
}

int	ft_while(t_data *data)
{
	if (ft_while_per(data))
		return (1);
	if (ft_while_odd(data))
		return (1);
	if (ft_join(data))
		return (1);
	return (0);
}

int	ft_philo_dead(t_data *data)
{
	int	i;

	i = -1;
	while (i++ < data->nb_of)
	{
		if (data->philo[i].is_dead)
			return (1);
	}
	return (0);
}
