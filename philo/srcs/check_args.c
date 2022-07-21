/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:10:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/07/21 13:16:02 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_num_len(int nbr, int *size)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		*size += 1;
		nb *= -1;
	}
	if (nb < 10 && nb >= 0)
		*size += 1;
	else
	{
		ft_num_len(nbr % 10, size);
		ft_num_len(nbr / 10, size);
	}
}

int	ft_check_str(char *s)
{
	int	size;
	
	size = 0;
	ft_num_len(ft_atol(s), &size);
	if (ft_strlen(s) != size || ft_atol(s) < 0)
		return (1);
	return (0);
}

int	ft_check_all(char **args, int nb)
{
	int	i;

	i = 1;
	while (i < nb)
	{
		if (ft_check_str(args[i]))
			return (1);
		++i;
	}
	return (0);
}

int	ft_parse(t_data *data, char **av, int ac)
{
	data->nb_of = ft_atol(av[1]);
	data->tt_die = ft_atol(av[2]);
	data->tt_eat = ft_atol(av[3]);
	data->tt_sleep = ft_atol(av[4]);
	data->is_dead = 0;
	data->start = ft_get_time();
	if (ac == 6)
		data->nb_to_eat = ft_atol(av[5]);
	else
		data->nb_to_eat = 0;
	if (ft_init_philo(data, data->nb_of))
		return (1);
	return (0);
}
