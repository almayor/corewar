/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:59 by user              #+#    #+#             */
/*   Updated: 2020/11/06 15:13:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
