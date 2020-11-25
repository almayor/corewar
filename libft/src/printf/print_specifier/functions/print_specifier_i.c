/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/07/01 23:20:34 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	print_digits(t_specifier *specif, intmax_t num, char *radix)
{
	if (num)
		pf_putuint(num < 0 ? -num : num, radix);
	else if (!specif->precision.isgiven || specif->precision.val)
		pf_putchar('0');
	return (0);
}

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
	intmax_t	num;

	num = *(intmax_t *)data;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		pf_putnchar('0', specif->npad_precision);
		pf_putnchar('0', specif->npad_width);
		print_digits(specif, num, "0123456789");
	}
	else
	{
		print_sign(specif, num < 0);
		pf_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "0123456789");
		pf_putnchar(' ', specif->npad_width);
	}
	return (0);
}

static int	print_right_aligned(t_specifier *specif, void *data)
{
	intmax_t	num;

	num = *(intmax_t *)data;
	if (specif->zero)
	{
		print_sign(specif, num < 0);
		pf_putnchar('0', specif->npad_precision);
		pf_putnchar('0', specif->npad_width);
		print_digits(specif, num, "0123456789");
	}
	else
	{
		pf_putnchar(' ', specif->npad_width);
		print_sign(specif, num < 0);
		pf_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "0123456789");
	}
	return (0);
}

int			print_specifier_i(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}
