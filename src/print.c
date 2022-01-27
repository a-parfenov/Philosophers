/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:50:01 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/27 12:50:02 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *msg, unsigned long t)
{
	pthread_mutex_lock(&philo->info->printer);
	printf("%lu %d %s\n", t - philo->time_start, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->info->printer);
}
