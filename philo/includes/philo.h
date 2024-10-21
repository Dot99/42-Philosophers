/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:49:22 by gude-jes          #+#    #+#             */
/*   Updated: 2024/10/21 09:33:34 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup mandatory Mandatory
 * @{
 * @file philo.h
 * @brief Philosophers Header
*/

#ifndef PHILO_H
# define PHILO_H

# include <memory.h> // memset()
# include <stdio.h> // printf()
# include <stdlib.h> // malloc(), free()
# include <unistd.h> // write(), usleep()
# include <sys/time.h> // gettimeofday()
# include <pthread.h> // POSIX thread API
# include <stdbool.h> // boolean data type


# define WRONG_ARG "Invalid Arguments"
# define MTX_ERROR "Mutex Error"
# define MLC_ERROR "Malloc Error"
# define THR_ERROR "Thread error"
# define THR_JOIN "Thread join error"

# define FORK "has taken the fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DEATH "died\n"
# define DEFORK "has released the fork\n"

# define DEBUG false

/**
 * @brief Struct of arguments
 * @param nbr_philo Number of philosophers
 * @param time_to_die Time for a philo to die
 * @param time_to_eat Time for a philo to eat
 * @param time_to_sleep Time for a philo to sleep
 * @param eat_time Times that a philo has to eat
 * @param mutex Mutex to lock the struct
 * @param end Variable to check if the program must end
*/
typedef struct s_args
{
	int					nbr_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_times;
	pthread_mutex_t		mutex;
	bool				end;

}				t_args;

/**
 * @brief Philosophers Struct
 * @param nbr_philo Number of the philo
 * @param num_eat Number of meals eated by philo
 * @param start Start time of each philo
 * @param last_meal Last time a philo has eaten
 * @param l_fork Left Fork Mutex
 * @param r_fork Right Fork Mutex
 * @param t_id Thread Id of Philo
 * @param args Struct of args
*/
typedef struct s_philo
{
	int					nbr_philo;
	int					num_eat;
	suseconds_t			start;
	suseconds_t			last_meal;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_t			t_id;
	t_args				*args;
}			t_philo;

bool			valid_args(int ac, char **av);
bool			init_args(t_args *args, char **av);
bool			start(t_args *args, pthread_mutex_t *fork, t_philo *philo);
bool			is_philo_dead(t_args *args, t_philo *philo, int *philo_fed);
void			pick_forks(t_philo *philo);
void			lay_forks(t_philo *philo);
void			handler(t_philo *philo, char *event);
void			all_fed(t_args *args);
void			*loop(void *_philo);
void			free_all(pthread_mutex_t *forks, t_args *args, t_philo *philo);
void			dead(pthread_mutex_t *forks, t_args *args, t_philo *philo,
					char *error);
pthread_mutex_t	*init_forks(t_args *args);
t_philo			*init_philos(t_args *args, pthread_mutex_t *forks);
suseconds_t		get_time(void);

#endif

/**@} */