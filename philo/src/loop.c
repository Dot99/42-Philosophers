/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:36:21 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/21 09:09:09 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file loop.c
 * @brief Core of the program
*/

#include "philo.h"

/**
 * @brief Function to make philo sleep
 * 
 * @param philo Philo Struct
*/
static inline void	_sleep(t_philo *philo)
{
	handler(philo, SLEEP);
	usleep(philo->args->time_to_sleep);
}

/**
 * @brief Function to make each philo eat
 * 
 * @param philo Philo Struct
*/
void	eat(t_philo *philo)
{
	pick_forks(philo);
	pthread_mutex_lock(&philo->args->mutex);
	philo->last_meal = get_time();
	philo->num_eat++;
	pthread_mutex_unlock(&philo->args->mutex);
	handler(philo, EAT);
	usleep(philo->args->time_to_eat);
	lay_forks(philo);
}

/**
 * @brief Main loop of the program
 * 
 * @param _philo Pointer to philo struct
*/
void	*loop(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	if (philo->args->nbr_philo == 1)
	{
		handler(philo, FORK);
		return (NULL);
	}
	while (true)
	{
		pthread_mutex_lock(&philo->args->mutex);
		if (philo->args->end)
		{
			pthread_mutex_unlock(&philo->args->mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->args->mutex);
		eat(philo);
		_sleep(philo);
		handler(philo, THINK);
	}
	return (NULL);
}

/**@} */