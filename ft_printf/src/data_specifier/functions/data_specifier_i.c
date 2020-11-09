/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_specifier_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:47 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 19:42:17 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	data_specifier_i(t_specifier *specif, void **data, va_list ap)
{
	if (!(*data = malloc(sizeof(intmax_t))))
		return ((errno = ENOMEM));
	if (specif->length == NONE)
		*(intmax_t *)*data = va_arg(ap, int);
	else if (specif->length == h)
		*(intmax_t *)*data = va_arg(ap, int);
	else if (specif->length == l)
		*(intmax_t *)*data = va_arg(ap, long);
	else if (specif->length == ll)
		*(intmax_t *)*data = va_arg(ap, long long);
	else if (specif->length == hh)
		*(intmax_t *)*data = va_arg(ap, int);
	else if (specif->length == j)
		*(intmax_t *)*data = va_arg(ap, intmax_t);
	return (0);
}
