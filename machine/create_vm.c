/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayatsyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 23:24:14 by ayatsyny          #+#    #+#             */
/*   Updated: 2017/06/12 23:24:17 by ayatsyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"

char	*create_vm(void)
{
	char *vm;

	vm = ft_strnew(MEM_SIZE);
	return (vm);
}


