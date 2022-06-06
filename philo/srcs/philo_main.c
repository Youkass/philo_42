/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:34:40 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/06 15:09:32 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_create_data(t_philo **data, int nb)
{
	*data = malloc(sizeof(t_philo) * (nb + 1));
	if (!*data)
		return (1);
	return (0);
}

void	ft_routine(void *philo)
{
	
}

int	ft_init_philo(t_data *data, int nb)
{
	if (ft_create_data(&data, nb))
		return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	
	(void)av;
	(void)data;
	if (ac == 5 )
	{
		return (0);
	}
	else if  (ac == 6)
	{
		return (0);
	}
	else
		return (ft_invalid_nb(), 1);
}
