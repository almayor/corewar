/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:30:59 by unite             #+#    #+#             */
/*   Updated: 2020/07/01 23:08:16 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	print_prefix(t_specifier *specif)
{
	(void)specif;
	pf_puts("0x");
	return (0);
}

static int	print_left_aligned(t_specifier *specif, void *data)
{
	uintmax_t	num;

	num = *(uintmax_t *)data;
	if (specif->zero)
	{
		print_prefix(specif);
		pf_putnchar('0', specif->npad_precision);
		pf_putnchar('0', specif->npad_width);
		pf_putuint(num, "0123456789abcdef");
	}
	else
	{
		print_prefix(specif);
		pf_putnchar('0', specif->npad_precision);
		pf_putuint(num, "0123456789abcdef");
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
		print_prefix(specif);
		pf_putnchar('0', specif->npad_precision);
		pf_putnchar('0', specif->npad_width);
		pf_putuint(num, "0123456789abcdef");
	}
	else
	{
		pf_putnchar(' ', specif->npad_width);
		print_prefix(specif);
		pf_putnchar('0', specif->npad_precision);
		pf_putuint(num, "0123456789abcdef");
	}
	return (0);
}

int			print_specifier_p(t_specifier *specif, void *data)
{
	if (specif->minus)
		print_left_aligned(specif, data);
	else
		print_right_aligned(specif, data);
	return (0);
}
