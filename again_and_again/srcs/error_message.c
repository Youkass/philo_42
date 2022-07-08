/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:29:36 by yobougre          #+#    #+#             */
/*   Updated: 2022/07/08 13:29:42 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putstr_fd(int fd, char *s)
{
	write(fd, s, ft_strlen(s));
}

void	ft_invalid_args(void)
{
	ft_putstr_fd(2, "some of the arguments are not digits\n");
}

void	ft_invalid_nb(void)
{
	ft_putstr_fd(2, INV_NB_ARG);
}
