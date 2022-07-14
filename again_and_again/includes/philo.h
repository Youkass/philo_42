/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2021/10/19 15:08:54 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "includes.h"
# include "struct.h"

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/ft_atol.c                            */
/* -------------------------------------------------------------------------- */
int	ft_check(char c);
int	ft_space(char c);
long	ft_atol(char *nbr);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/utils.c                             */
/* -------------------------------------------------------------------------- */
int	ft_strlen(char *s);
int	ft_get_time(void);
int	ft_is_dead(t_philo *philo);

/* -------------------------------------------------------------------------- */
/*                        FILE = srcs/error_message.c                         */
/* -------------------------------------------------------------------------- */
void	ft_putstr_fd(int fd, char *s);
void	ft_invalid_args(void);
void	ft_invalid_nb(void);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/check_args.c                          */
/* -------------------------------------------------------------------------- */
void	ft_num_len(int nbr, int *size);
int	ft_check_str(char *s);
int	ft_check_all(char **args, int nb);
int	ft_parse(t_data *data, char **av, int ac);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/action.c                            */
/* -------------------------------------------------------------------------- */
void	ft_print_state(t_philo *philo, char *state);
void	ft_sleep(t_philo *philo);
int	ft_usleep(int time, t_philo *philo);
int	ft_eat(t_philo *philo);

/* -------------------------------------------------------------------------- */
/*                             FILE = srcs/main.c                             */
/* -------------------------------------------------------------------------- */
int	ft_create_data(t_data *data, int nb);
void	ft_init_last_meal(t_data *data);
int	ft_init_philo(t_data *data, int nb);
int	ft_join(t_data *data);
int	main(int ac, char **av);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/parsing.c                            */
/* -------------------------------------------------------------------------- */
int	ft_init_mutex(t_data *data);
int	ft_assign_fork(t_data *data);


#endif
