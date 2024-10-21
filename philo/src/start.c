/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:40:58 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/21 09:12:20 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file start.c
 * @brief Start of the thread cycle
*/

#include "philo.h"

/**
 * @brief Get the time object
 * @return suseconds_t Time in miliseconds
*/
suseconds_t	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

/**
 * @brief Checks if the program must end
 * 
 * @param philo Philo Struct
 * @param args Args Struct
*/
void	checker(t_philo *philo, t_args *args)
{
	int	philo_fed;
	int	i;

	philo_fed = 0;
	while (true)
	{
		i = -1;
		pthread_mutex_lock(&args->mutex);
		while (++i < args->nbr_philo)
		{
			if (is_philo_dead(args, &philo[i], &philo_fed))
				return ;
		}
		if (philo_fed == args->nbr_philo)
			return (all_fed(args));
		pthread_mutex_unlock(&args->mutex);
	}
}

/**
 * @brief Starts the threads
 * 
 * @param args Args Struct
 * @param fork Forks Struct
 * @param philo Philo Structs
 * @return true End
 * @return false Not End
*/
bool	start(t_args *args, pthread_mutex_t *fork, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < args->nbr_philo)
	{
		philo[i].start = get_time();
		if (pthread_create(&philo[i].t_id, NULL,
				loop, (void *)&philo[i]) != 0)
		{
			dead(fork, args, philo, THR_ERROR);
			return (false);
		}
	}
	checker(philo, args);
	i = -1;
	while (++i < args->nbr_philo)
	{
		if (pthread_join(philo[i].t_id, NULL) != 0)
		{
			dead(fork, args, philo, THR_JOIN);
			return (false);
		}
	}
	return (true);
}

/**@} */