/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:24:23 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/06 14:22:30 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "philo.h"

typedef struct	s_philo
{
	int				id;
	int				tt_die;
	int				tt_spleep;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
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
