/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:01:18 by yobougre          #+#    #+#             */
/*   Updated: 2022/07/07 13:49:24 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_state(t_philo *philo, char *state)
{
	printf("%d %d %s\n", ft_get_time() - philo->start, philo->id, state);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_state(philo, "is sleeping");
	ft_usleep(philo->tt_sleep, philo);
}

int	ft_usleep(int time, t_philo *philo)
{
	int	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
	{
		if (ft_is_dead(philo))
			return (1);
		usleep(50);
	}
	return (0);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print_state(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	ft_print_state(philo, "has taken a fork");
	ft_print_state(philo, "is eating");
	ft_usleep(philo->tt_eat, philo);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (0);
}
