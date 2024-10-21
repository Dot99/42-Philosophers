/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:03:16 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/21 08:59:36 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file forks.c
 * @brief Forks functions
*/

#include "philo.h"

/**
 * @brief Lay down forks
 * 
 * @param philo Philo fork
*/
void	lay_forks(t_philo *philo)
{
	if (philo->nbr_philo % 2 == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		if (DEBUG)
			handler(philo, DEFORK);
		pthread_mutex_unlock(philo->r_fork);
		if (DEBUG)
			handler(philo, DEFORK);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		if (DEBUG)
			handler(philo, DEFORK);
		pthread_mutex_unlock(philo->l_fork);
		if (DEBUG)
			handler(philo, DEFORK);
	}
}

/**
 * @brief Pick up the forks
 * 
 * @param philo Philo fork
*/
void	pick_forks(t_philo *philo)
{
	if (philo->nbr_philo % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		handler(philo, FORK);
		pthread_mutex_lock(philo->r_fork);
		handler(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		handler(philo, FORK);
		pthread_mutex_lock(philo->l_fork);
		handler(philo, FORK);
	}
}

/**@} */