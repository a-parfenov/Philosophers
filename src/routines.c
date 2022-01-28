/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:50:08 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/28 12:47:34 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start(void *argv)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *) argv;
	philo->time_start = get_time();
	philo->start_eating = philo->time_start;
	philo->state = living;
	if (philo->id % 2)
		start_sleep(philo);
	while (philo->state != done)
	{
		if (philo->state != done)
		{
			try_take_forks(philo);
			eat(philo);
			put_forks(philo);
		}
		if (philo->state != done && philo->count_eat == philo->info->max_eat)
			philo->state = done;
		if (philo->state != done)
			start_sleep(philo);
	}
	return (NULL);
}

static int	check_philo_states(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		if (info->philos[i].state != done)
			return (0);
		++i;
	}
	return (1);
}

static void	modify_states(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		info->philos[i].state = done;
		++i;
	}
}

void	*monitor_routine(void *argv)
{
	int				i;
	unsigned long	t;
	t_info			*info;

	info = (t_info *) argv;
	while (1)
	{
		i = 0;
		t = get_time();
		while (i < info->n_philo)
		{
			if (info->philos[i].state == living
				&& t - info->philos[i].start_eating > info->time_to_die)
			{
				modify_states(info);
				print_message(&info->philos[i], "died", t);
				return (ft_error("STOP"));
			}
			++i;
		}
		if (check_philo_states(info))
			return (ft_error("STOP"));
		usleep(330);
	}
	return (NULL);
}
