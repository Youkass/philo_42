/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:24:05 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/05 10:44:05 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f'
		|| c == '\v')
		return (1);
	return (0);
}

long	ft_atol(char *nbr)
{
	int			nega;
	long long	output;
	int			i;

	output = 0;
	i = 0;
	nega = 1;
	while (ft_space(nbr[i]))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			nega *= -1;
		i++;
	}
	while (ft_check(nbr[i]))
		output = (output * 10) + (nbr[i++] - 48);
	return (output * nega);
}
