/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:27:31 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/23 14:33:07 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_state(t_philo *philo, char *state)
{
	printf("%d %d is %s\n", ft_get_time(), philo->id, state);
}

static void	ft_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(*fork);
	ft_print_state(philo, "has taken a fork");
}

int	ft_take_fork(t_data *data, int index)
{
	if (index < 1)
	{
		ft_fork(data->philo[index], &(data->philo[nb_of - 1]->r_fork));
		ft_fork(data->philo[index], &(data->philo[index]->r_fork));
		ft_eat(data, index);
		pthread_mutex_unlock(data->philo[index]->r_fork);
		pthread_mutex_unlock(data->philo[nb_of - 1]->r_fork);
	}
	else
	{
		ft_fork(data->philo[index], &(data->philo[index - 1]->r_fork));
		ft_fork(data->philo[index], &(data->philo[index]->r_fork));
		ft_eat(data, index);
		pthread_mutex_unlock(data->philo[index - 1]->r_fork);
		pthread_mutex_unlock(data->philo[index]->r_fork);
		return (0);
	}
}

int	ft_eat(t_data *data, int index)
{
	if (ft_get_time() - philo.last_meal >= philo.tt_die || data.is_dead)
	{
		data.is_dead = 1;
		return (1);
	}
	ft_print_state(data->philo[index], "is eating");
	data->philo[index].last_meal = ft_get_time();
	return (0);
}
