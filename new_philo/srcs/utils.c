/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:39:49 by yobougre          #+#    #+#             */
/*   Updated: 2022/07/01 10:01:14 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_get_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_philo_dead(t_philo *philo)
{
	if (ft_get_time() - philo->last_meal >= philo->tt_die)
		return (1);
	return (0);
}

int	ft_check_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of)
	{
		if (ft_philo_dead(&(data->philo[i]))
			return (1);
		++i;
	}
	return (0);
}
