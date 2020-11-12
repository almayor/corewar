/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:44:49 by unite             #+#    #+#             */
/*   Updated: 2020/07/01 23:11:02 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	pf_putuint(uintmax_t num, const char *radix)
{
	size_t		base_len;
	uintmax_t	factor;

	base_len = ft_strlen(radix);
	factor = 1;
	while (num / factor >= base_len)
		factor *= base_len;
	while (factor >= 1)
	{
		pf_putchar(radix[num / factor]);
		num %= factor;
		factor /= base_len;
	}
	return (0);
}
