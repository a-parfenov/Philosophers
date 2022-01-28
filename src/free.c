/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:49:33 by aleslie           #+#    #+#             */
/*   Updated: 2022/01/28 13:20:08 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philo)
		pthread_mutex_destroy(&info->forks[i]);
	pthread_mutex_destroy(&info->m_print);
}

void	free_memory(t_info *info)
{
	free(info->philos);
	free(info->forks);
	free(info);
	info = NULL;
}
