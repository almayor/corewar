/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_specifier_o.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 18:48:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	complete_specifier_o(t_specifier *specif, void *data)
{
	uintmax_t	num;
	size_t		ndigits;
	size_t		prefix;

	num = *(uintmax_t *)data;
	if (num)
		ndigits = get_ndigits_uint(num, 8);
	else
		ndigits = !specif->precision.isgiven ||
					specif->precision.val ||
					specif->hash;
	prefix = (specif->hash && num > 0) ? 1 : 0;
	specif->npad_precision = 0;
	specif->npad_width = 0;
	if (specif->precision.isgiven)
		specif->npad_precision = specif->precision.val -
			min(specif->precision.val, ndigits);
	if (specif->width.isgiven)
		specif->npad_width = specif->width.val -
			min(specif->width.val, specif->npad_precision + ndigits + prefix);
	return (0);
}
