/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:29:05 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/21 09:07:03 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file handler.c
 * @brief Function to handle the prints
*/

#include "philo.h"

/**
 * @brief Handles the printing of the program
 * 
 * @param philo Philo struct
 * @param event Type of event
*/
void	handler(t_philo *philo, char *event)
{
	suseconds_t	timestamp;

	pthread_mutex_lock(&philo->args->mutex);
	if (philo->args->end)
	{
		pthread_mutex_unlock(&philo->args->mutex);
		return ;
	}
	timestamp = get_time() - philo->start;
	printf("%ld %d %s", timestamp, philo->nbr_philo, event);
	pthread_mutex_unlock(&philo->args->mutex);
}

/**@} */