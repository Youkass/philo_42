/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:27:31 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/24 15:35:42 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_state(t_philo *philo, char *state)
{
	printf("%d %d is %s\n", ft_get_time(), philo->id, state);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_state(philo, "is sleeping");
	usleep(philo->tt_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print_state(philo, "is thinking");
	usleep(philo->tt_think);
}

int	ft_take_fork(t_philo *philo)
{
	if (philo->is_dead)
		return (1);
	pthread_mutex_lock(philo->l_fork);
	ft_print_state(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	ft_print_state(philo, "has taken a fork");
	if (ft_eat(philo))
		return (1);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	if (ft_get_time() - philo->last_meal >= philo->tt_die || data->is_dead)
	{
		philo->is_dead = 1;
		return (1);
	}
	ft_print_state(philo, "is eating");
	philo->last_meal = ft_get_time();
	usleep(philo->tt_eat);
	return (0);
}
