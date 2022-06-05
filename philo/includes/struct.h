/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:24:23 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/05 17:08:31 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "philo.h"

typedef struct	s_philo
{
	int		id;
	int		tt_die;
	int		tt_spleep;
}	t_philo;

typedef struct	s_data
{
	int		tt_eat;
	int		tt_die;
	int		tt_sleep;
	int		nb_of;
	t_philo	*philo;
}	t_data;

#endif
