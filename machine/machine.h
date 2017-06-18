/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 22:46:57 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/06/12 22:47:03 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../op.h"

typedef struct		s_fork
{
	int				carry : 1; 			// carry flag
	int 			live : 1;			// process worker
	size_t			pc;           	 	// position in char elements
	int				reg[REG_NUMBER];	// registers of the processor
}					t_fork;

typedef struct		s_list_forks
{
	t_fork			fork;
	t_fork			*prev;
	t_fork			*next;
}					t_list_forks;

typedef struct		s_tasks
{
	t_fork			*p_fork;
	struct s_query	*prev;
	struct s_query	*next;
	unsigned		time_cycle;
}					t_tasks;

typedef	struct		s_machine
{
	t_list_forks	head;
	t_list_forks	tail;
	unsigned		count_live;
	t_tasks			top;
	t_tasks			buttom;
	header_t		*player;
}					t_machine;

#endif