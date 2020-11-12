/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/07/01 23:26:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <math.h>

static int	print_sign(t_specifier *specif, int isnegative)
{
	if (isnegative)
		pf_putchar('-');
	else if (specif->space)
		pf_putchar(' ');
	else if (specif->plus)
		pf_putchar('+');
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	long double	num;
	long double num_abs;

	num = *(long double *)data;
	num_abs = num < 0 ? -num : num;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		pf_putnchar('0', specif->npad_width);
		pf_putfloat(num_abs, "0123456789", specif->precision.val, specif->hash);
	}
	else
	{
		print_sign(specif, num < 0);
		pf_putfloat(num_abs, "0123456789", specif->precision.val, specif->hash);
		pf_putnchar(' ', specif->npad_width);
	}
	return (0);
}

static int	print_right_aligned(t_specifier *specif, void *data)
{
	long double	num;
	long double num_abs;

	num = *(long double *)data;
	num_abs = num < 0 ? -num : num;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		pf_putnchar('0', specif->npad_width);
		pf_putfloat(num_abs, "0123456789", specif->precision.val, specif->hash);
	}
	else
	{
		pf_putnchar(' ', specif->npad_width);
		print_sign(specif, num < 0);
		pf_putfloat(num_abs, "0123456789", specif->precision.val, specif->hash);
	}
	return (0);
}

static int	print_special(t_specifier *specif, void *data)
{
	long double	num;

	num = *(long double *)data;
	if (!specif->minus)
		pf_putnchar(' ', specif->npad_width);
	if (isnan(num))
		pf_puts("(null)");
	else if (!isfinite(num) && num > 0)
		pf_puts("(inf)");
	else if (!isfinite(num) && num < 0)
		pf_puts("(-inf)");
	if (specif->minus)
		pf_putnchar(' ', specif->npad_width);
	return (0);
}

int			print_specifier_f(t_specifier *specif, void *data)
{
	long double	num;

	num = *(long double *)data;
	if (isnan(num) || !isfinite(num))
		return (print_special(specif, data));
	if (specif->minus)
		return (print_left_aligned(specif, data));
	else
		return (print_right_aligned(specif, data));
}
