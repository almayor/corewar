/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ndigits_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:44:49 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 19:44:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

size_t	get_ndigits_int(intmax_t num, size_t base_len)
{
	size_t		ndigits;
	intmax_t	factor;

	if (num == 0)
		return (1);
	ndigits = 0;
	factor = base_len;
	while (num)
	{
		ndigits += 1;
		num /= factor;
	}
	return (ndigits);
}
