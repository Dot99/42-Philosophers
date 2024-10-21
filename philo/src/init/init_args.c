/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:32:05 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/21 08:57:09 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file init_args.c
 * @brief Initiate the struct args with value from argv
 */
#include "philo.h"

/**
 * @brief Convert string to int
 * 
 * @param str String to be converted
 * @return int Number converted
*/
int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/**
 * @brief Main function to initialize arguments
 * 
 * @param args Struct of the arguments
 * @param av Matrix of the arguments
 * @return true Arguments are correct
 * @return false Wrong Arguments
 */
bool	init_args(t_args *args, char **av)
{
	args->nbr_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]) * 999;
	args->time_to_sleep = ft_atoi(av[4]) * 999;
	args->eat_times = -1;
	if (av[5])
		args->eat_times = ft_atoi(av[5]);
	if (args->nbr_philo == 0 || args->eat_times == 0)
	{
		dead(NULL, args, NULL, WRONG_ARG);
		return (false);
	}
	if (pthread_mutex_init(&args->mutex, NULL) != 0)
	{
		dead(NULL, args, NULL, MTX_ERROR);
		return (false);
	}
	args->end = false;
	return (true);
}

/**@} */