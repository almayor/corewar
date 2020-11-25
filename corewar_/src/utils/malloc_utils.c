/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:25:21 by user              #+#    #+#             */
/*   Updated: 2020/11/10 02:20:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Replicates behaviour of `malloc` from `libc`, but fails on
** memory allocation errors.
*/

void	*ft_xmalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem && !size)
		terminate(MALLOC_ERROR);
	return (mem);
}

/*
** Replicates behaviour of `calloc` from `libc`, but fails on
** memory allocation errors.
*/

void	*ft_xcalloc(size_t count, size_t size)
{
	void	*mem;

	mem = ft_calloc(count, size);
	if (!mem && !size)
		terminate(MALLOC_ERROR);
	return (mem);
}
