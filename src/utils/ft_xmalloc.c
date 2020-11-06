/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:38:01 by user              #+#    #+#             */
/*   Updated: 2020/11/06 15:13:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
