/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:27:31 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/25 14:16:00 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_state(t_philo *philo, char *state)
{
	printf("%d %d %s\n", ft_get_time() - philo->start, philo->id, state);
}

void	ft_sleep(t_philo *philo)
{
	ft_usleep(philo->tt_sleep);
	ft_print_state(philo, "is sleeping");
}

int	ft_take_fork(t_philo *philo)
{
	if (philo->is_dead)
		return (1);
	pthread_mutex_lock(philo->l_fork);
	ft_print_state(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->r_fork));
	ft_print_state(philo, "has taken a fork");
	if (ft_eat(philo))
		return (1);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(&(philo->r_fork));
	return (0);
}

int	ft_eat(t_philo *philo)
{
	if (ft_get_time() - philo->last_meal >= philo->tt_die)
	{
		philo->is_dead = 1;
		return (1);
	}
	ft_usleep(philo->tt_eat);
	ft_print_state(philo, "is eating");
	philo->last_meal = ft_get_time();
	return (0);
}

void	ft_usleep(int time)
{
	int	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(50);
}
