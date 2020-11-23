/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_specifier_f.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:02:50 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 19:22:59 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <math.h>

static int	get_npad_width(t_specifier *specif, long double num)
{
	size_t	sign;
	size_t	dot;
	size_t	nchar;

	if (!specif->width.isgiven)
		return (0);
	sign = num < 0 || specif->space || specif->plus;
	dot = (specif->precision.val > 0) || (specif->hash);
	nchar = sign + get_ndigits_int(num, 10) + dot + specif->precision.val;
	specif->npad_width = specif->width.val - min(specif->width.val, nchar);
	return (0);
}

static int	get_npad_width_special(t_specifier *specif, long double num)
{
	if (isnan(num))
		specif->npad_width = specif->width.val - min(specif->width.val, 5);
	else if (!isfinite(num) && num > 0)
		specif->npad_width = specif->width.val - min(specif->width.val, 5);
	else if (!isfinite(num) && num < 0)
		specif->npad_width = specif->width.val - min(specif->width.val, 6);
	return (0);
}

int			complete_specifier_f(t_specifier *specif, void *data)
{
	long double	num;

	num = *(long double *)data;
	if (!specif->precision.isgiven)
		specif->precision.val = 6;
	if (isnan(num) || !isfinite(num))
		return (get_npad_width_special(specif, num));
	else
		return (get_npad_width(specif, num));
}
