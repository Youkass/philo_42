/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:45:18 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/25 12:56:32 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_parse(t_data *data, char **av, int ac)
{
	data->nb_of = ft_atol(av[1]);
	data->tt_die = ft_atol(av[2]);
	data->tt_eat = ft_atol(av[3]);
	data->tt_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->nb_to_eat = ft_atol(av[5]);
	else
		data->nb_to_eat = -1;
	if (ft_init_philo(data, ac))
		return (1);
	return (0);
}
