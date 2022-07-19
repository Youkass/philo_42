/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:04:13 by yobougre          #+#    #+#             */
/*   Updated: 2022/07/19 12:08:30 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_state(t_philo *philo, char *state)
{
	printf("%d %d %s\n", ft_get_time() - philo->start, philo->id, state);
}

int	ft_sleep(t_philo *philo)
{
	ft_print_state(philo, "is sleeping");
	if (ft_usleep(philo->tt_sleep, philo))
		return (1);
	return (0);
}

int	ft_usleep(int time, t_philo *philo)
{
	int	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
	{
		if (ft_is_dead(philo))
			return (1);
		usleep(10);
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
	if (ft_usleep(philo->tt_eat, philo))
		return (printf("je meurt ici num : %d\n", philo->id), 1);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (0);
}
