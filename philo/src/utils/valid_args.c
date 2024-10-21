/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:23:38 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/21 09:05:57 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file valid_args.c
 * @brief Validate arguments
*/
#include "philo.h"

/**
 * @brief Check if char is digit
 * 
 * @param c Character
 * @return true Is digit
 * @return false Not digit
*/
static bool	is_digit(char c)
{
	return ((c >= '0' && c <= '9'));
}

/**
 * @brief Checks if each string is digit
 * 
 * @param av Arguments passed to main program
 * @return true All arguments are digit
 * @return false Not all arguments are digit
*/
static bool	is_alldigits(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/**
 * @brief Validates arguments
 * 
 * @param ac Number of arguments
 * @param av String for each argument
 * @return true All valid
 * @return false Not all valid
*/
bool	valid_args(int ac, char **av)
{
	if (!(ac == 5 || ac == 6) || !is_alldigits(av))
		return (false);
	return (true);
}

/**@} */