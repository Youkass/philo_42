/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:24:23 by yobougre          #+#    #+#             */
/*   Updated: 2022/06/25 13:28:55 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "philo.h"

typedef struct	s_philo
{
	pthread_t		thread_id;
	int				id;
	int				tt_die;
	int				tt_sleep;
	int				tt_eat;
	int				nb_to_eat;
	int				is_dead;
	long			last_meal;
	int				start;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	r_fork;
}	t_philo;

typedef struct	s_data
{
	int		tt_eat;
	int		tt_die;
	int		tt_sleep;
	int		nb_of;
	int		is_dead;
	int		nb_to_eat;
	t_philo	*philo;
}	t_data;

#endif
