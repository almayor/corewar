/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_specifier_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:17:38 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 18:12:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	data_specifier_u(t_specifier *specif, void **data, va_list ap)
{
	if (!(*data = malloc(sizeof(unsigned long long))))
		return ((errno = ENOMEM));
	if (specif->length == NONE)
		*(uintmax_t *)*data = va_arg(ap, unsigned);
	else if (specif->length == h)
		*(uintmax_t *)*data = va_arg(ap, unsigned);
	else if (specif->length == l)
		*(uintmax_t *)*data = va_arg(ap, unsigned long);
	else if (specif->length == ll)
		*(uintmax_t *)*data = va_arg(ap, unsigned long long);
	else if (specif->length == hh)
		*(uintmax_t *)*data = va_arg(ap, unsigned);
	else if (specif->length == j)
		*(uintmax_t *)*data = va_arg(ap, uintmax_t);
	return (0);
}
