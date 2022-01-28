/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:42:46 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/28 11:50:09 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *msg, unsigned long t)
{
	pthread_mutex_lock(&philo->info->m_print);
	printf("%lu %d %s\n", t - philo->time_start, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->info->m_print);
}

int	print_error(void)
{
	printf("Wrong input!\nPlease use like: '\
./philo\033[0;31m a\033[0;32m b\033[0;33m c\033[0;34m d\033[0;35m e\033[0;37m'\
\n\033[0;31ma = [number_of_philosophers]\n\033[0;32mb = [time_to_die]\
\n\033[0;33mc = [time_to_eat]\n\033[0;34md = [time_to_sleep]\
\n\033[0;35me = [number_of_times_each_philosoppher_must_eat]\
\n\033[0;37mEvery value but \033[0;35me\033[0;37m is mandatory.\n");
	return (1);
}
