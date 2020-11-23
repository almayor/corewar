/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier_o.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/07/01 23:08:23 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	print_digits(t_specifier *specif, uintmax_t num, char *radix)
{
	if (num)
		pf_putuint(num, radix);
	else if (!specif->precision.isgiven || specif->precision.val ||
			specif->hash)
		pf_putchar('0');
	return (0);
}

static int	print_prefix(t_specifier *specif, uintmax_t num)
{
	if (specif->hash && num != 0)
		pf_puts("0");
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	uintmax_t	num;

	num = *(uintmax_t *)data;
	if (specif->zero)
	{
		print_prefix(specif, num);
		pf_putnchar('0', specif->npad_precision);
		pf_putnchar('0', specif->npad_width);
		print_digits(specif, num, "01234567");
	}
	else
	{
		print_prefix(specif, num);
		pf_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "01234567");
		pf_putnchar(' ', specif->npad_width);
	}
	return (0);
}

static int	print_right_aligned(t_specifier *specif, void *data)
{
	uintmax_t	num;

	num = *(uintmax_t *)data;
	if (specif->zero)
	{
		print_prefix(specif, num);
		pf_putnchar('0', specif->npad_precision);
		pf_putnchar('0', specif->npad_width);
		print_digits(specif, num, "01234567");
	}
	else
	{
		pf_putnchar(' ', specif->npad_width);
		print_prefix(specif, num);
		pf_putnchar('0', specif->npad_precision);
		print_digits(specif, num, "01234567");
	}
	return (0);
}

int			print_specifier_o(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}
