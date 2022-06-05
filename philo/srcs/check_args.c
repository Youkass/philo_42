/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:39:33 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/05 16:54:09 by yobougre         ###   ########.fr       */
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
		ft_num_len(nbr / 10, size);
		ft_num_len(nbr % 10, size);
	}
}

int	ft_check_str(char *s)
{
	int	size;

	ft_num_len(ft_atol(nbr), &size);
	if (ft_strlen(s) != size)
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
