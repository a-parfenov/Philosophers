/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:49:18 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/27 12:49:21 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

enum e_state
{
	living,
	creating,
	done
};

typedef struct s_info	t_info;
typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	t_info			*info;
	int				state;
	int				count_eat;
	int				lfork;
	int				rfork;
	unsigned long	time_start;
	unsigned long	start_eating;
}	t_philo;

typedef struct s_info
{
	t_philo			*philos;
	int				n_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				max_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printer;
}	t_info;

int				ft_atoi(const char *str);
unsigned long	get_time(void);
t_info			*init_info(char **argv, int argc);
void			print_message(t_philo *philo, char *msg, unsigned long t);
void			free_memory(t_info **info);
void			destroy_forks(t_info *info);
void			start_sleep(t_philo *philo);
void			eat(t_philo *philo);
void			try_take_forks(t_philo *philo);
void			put_forks(t_philo *philo);
void			*start(void *argv);
void			*monitor_routine(void *argv);
void			*ft_error(char *msg);

#endif