/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:02:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/07/07 14:32:48 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_philo
{
	pthread_t		thread_id;
	int				tt_eat;
	int				tt_die;
	int				tt_sleep;
	int				nb_of;
	int				nb_to_eat;
	int				last_meal;
	int				start;
	int				is_dead;
	void			*data;
}	t_philo;

typedef struct	s_data
{
	pthread_mutex_t	*forks;
	int				tt_eat;
	int				tt_die;
	int				tt_sleep;
	int				nb_of;
	int				nb_to_eat;
	int				start;
	int				is_dead;
	t_philo			*philo;
}	t_data;

#endif 
