/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:32:58 by yobougre          #+#    #+#             */
/*   Updated: 2022/07/08 14:02:44 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_create_data(t_data *data, int nb)
{
	data->philo = malloc(sizeof(t_philo) * (nb + 1));
	if (!data->philo)
		return (1);
	return (0);
}

void	ft_init_last_meal(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of)
		data->philo[i++].last_meal = ft_get_time();
	data->is_dead = 0;
}

int	ft_init_philo(t_data *data, int nb)
{
	int	i;

	i = 0;
	if (ft_create_data(data, nb))
		return (1);
	while (i < data->nb_of)
	{
		data->philo[i].tt_die = data->tt_die;
		data->philo[i].tt_sleep = data->tt_sleep;
		data->philo[i].tt_eat = data->tt_eat;
		data->philo[i].id = i + 1;
		data->philo[i].is_dead = &(data->is_dead);
		data->philo[i].start = ft_get_time();
		if (data->nb_to_eat > -1)
			data->philo[i].nb_to_eat = data->nb_to_eat;
		++i;
	}
	ft_assign_fork(data);
	ft_init_last_meal(data);
	return (0);
}

int	ft_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of)
	{
		if (pthread_join(data->philo[i].thread_id, NULL))
			return (1);
		++i;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	
	if (ac >= 5 && ac <= 6)
	{
		if (ft_check_all(av, ac))
			return (ft_invalid_args(), 1);
		if (ft_parse(&data, av, ac))
			return (1);
		if (ft_create_philo(&data))
			return (1);
		if (ft_join(&data))
			return (1);
		free(data.philo);
		return (0);
	}
	else
		return (ft_invalid_nb(), 1);
}
