/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 21:44:57 by unite             #+#    #+#             */
/*   Updated: 2020/07/01 23:29:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static intmax_t	power(intmax_t base, uintmax_t exp)
{
	intmax_t	res;

	res = 1;
	while (exp-- > 0)
		res *= base;
	return (res);
}

int				pf_putfloat(long double num, const char *radix,
							size_t precision, int print_dot)
{
	uintmax_t	factor;
	intmax_t	int_part;
	intmax_t	frc_part;
	size_t		frc_ndigits;

	factor = power(ft_strlen(radix), precision);
	if (num < 0)
		num = num - 0.5 / factor;
	else
		num = num + 0.5 / factor;
	int_part = (intmax_t)num;
	frc_part = (num - int_part) * factor;
	pf_putint(int_part, radix);
	if (precision)
	{
		frc_ndigits = get_ndigits_int(frc_part, ft_strlen(radix));
		pf_putchar('.');
		pf_putnchar('0', precision - frc_ndigits);
		pf_putint(frc_part, radix);
	}
	else if (print_dot)
		pf_putchar('.');
	return (0);
}
