/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:27:31 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/12 14:35:02 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_state(t_philo *philo, char *state)
{
	printf("%d %d is %s\n", ft_get_time(), philo->id, state);
}

int	ft_take_fork(t_data *data, int index)
{
	if (index < 1)
	{
		pthread_mutex_lock(data->philo[nb_of - 1]->r_fork);
		ft_print_state(data->philo[index], "has taken a fork");
		ft_eat(data->philo[index]);
		pthread_mutex_unlock(data->philo[nb_of - 1]->r_fork);
	}
	else
	{
		pthread_mutex_lock(data->philo[index - 1]->r_fork);
		ft_print_state(data->philo[index], "has taken a fork");
		ft_eat(data->philo[index]);
		pthread_mutex_unlock(data->philo[index - 1]->r_fork);
	}
}

int	ft_eat(t_philo philo)
{
}
