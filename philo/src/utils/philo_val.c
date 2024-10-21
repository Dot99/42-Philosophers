/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:43:36 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/21 09:03:44 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file philo_val.c
 * @brief Eating related functions
*/

#include "philo.h"

/**
 * @brief Check if philo is hugry
 * 
 * @param philo Philo Struct
 * @return true Hungry
 * @return false Not Hungry
*/
static inline bool	hungry(t_philo *philo)
{
	return ((get_time() - philo->last_meal) > philo->args->time_to_die);
}

/**
 * @brief Checks if philo is dead
 * 
 * @param args Args Struct
 * @param philo Philo Struct
 * @param philo_fed Philo is fed
 * @return true Dead
 * @return false Not Dead
*/
bool	is_philo_dead(t_args *args, t_philo *philo, int *philo_fed)
{
	if (args->eat_times > 0 && philo->num_eat >= args->eat_times)
		(*philo_fed)++;
	if (hungry(philo))
	{
		pthread_mutex_unlock(&args->mutex);
		handler(philo, DEATH);
		pthread_mutex_lock(&args->mutex);
		args->end = true;
		pthread_mutex_unlock(&args->mutex);
		return (true);
	}
	return (false);
}

/**
 * @brief Prints message that all philo are done eating
 * @param args Args Struct
*/
void	all_fed(t_args *args)
{
	args->end = true;
	printf("Philosophers are done eating! Each one ate %d\n", args->eat_times);
	pthread_mutex_unlock(&args->mutex);
}

/**@} */