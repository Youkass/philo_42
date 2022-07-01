/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:01:18 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/30 14:01:52 by yobougre         ###   ########.fr       */
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
	ft_usleep(philo->tt_sleep);
}

void	ft_usleep(int time)
{
	int	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(50);
}
