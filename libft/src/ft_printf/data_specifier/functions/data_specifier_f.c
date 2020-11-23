/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_specifier_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:59:17 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 18:16:14 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	data_specifier_f(t_specifier *specif, void **data, va_list ap)
{
	if (!(*data = malloc(sizeof(long double))))
		return ((errno = ENOMEM));
	if (specif->length == NONE)
		*(long double *)*data = va_arg(ap, double);
	else if (specif->length == L || specif->length == l)
		*(long double *)*data = va_arg(ap, long double);
	return (0);
}
