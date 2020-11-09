/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_specifier_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:17:51 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 19:23:14 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	complete_specifier_u(t_specifier *specif, void *data)
{
	uintmax_t	num;
	size_t		ndigits;

	num = *(uintmax_t *)data;
	ndigits = get_ndigits_uint(num, 10);
	specif->npad_precision = 0;
	specif->npad_width = 0;
	if (specif->precision.isgiven)
		specif->npad_precision = specif->precision.val -
			min(specif->precision.val, ndigits);
	if (specif->width.isgiven)
		specif->npad_width = specif->width.val -
			min(specif->width.val, specif->npad_precision + ndigits);
	return (0);
}
