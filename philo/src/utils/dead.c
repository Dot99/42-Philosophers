/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:58:29 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/21 08:49:10 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file dead.c
 * @brief Handles errors and frees structs
 */
#include "philo.h"

/**
 * @brief Get the length of string
 * 
 * @param str String
 * @return int Length of string
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * @brief Free everything
 * 
 * @param forks Forks mutex
 * @param args Args struct
 * @param philo Philo struct
*/
void	free_all(pthread_mutex_t *forks, t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	if (args)
		pthread_mutex_destroy(&args->mutex);
	if (philo)
	{
		free(philo);
		philo = NULL;
	}
	if (forks)
	{
		while (i < args->nbr_philo)
		{
			pthread_mutex_destroy(&forks[i]);
			i++;
		}
		free(forks);
		forks = NULL;
	}
}

/**
 * @brief Function to end the program
 * 
 * @param forks Forks Mutex
 * @param args Args Struct
 * @param philo Philo Struct
 * @param error Type of error
*/
void	dead(pthread_mutex_t *forks, t_args *args, t_philo *philo, char *error)
{
	free_all(forks, args, philo);
	write(STDERR_FILENO, "ERROR: ", 7);
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
