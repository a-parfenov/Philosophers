/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:42:34 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/28 12:20:45 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_sleep(t_philo *philo)
{
	unsigned long	i;

	i = get_time();
	print_message(philo, "is sleeping", i);
	while (get_time() - i < philo->info->time_to_sleep)
		usleep(330);
	print_message(philo, "is thinking", get_time());
}

void	eat(t_philo *philo)
{
	unsigned long	i;

	i = get_time();
	philo->start_eating = i;
	print_message(philo, "is eating", i);
	while (get_time() - i < philo->info->time_to_eat)
		usleep(330);
	philo->count_eat += 1;
}

void	try_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->lfork]);
	print_message(philo, "has taken a lfork", get_time());
	pthread_mutex_lock(&philo->info->forks[philo->rfork]);
	print_message(philo, "has taken a rfork", get_time());
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
} 