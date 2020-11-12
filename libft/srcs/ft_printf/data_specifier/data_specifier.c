/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:03:37 by unite             #+#    #+#             */
/*   Updated: 2020/06/29 17:03:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	data_specifier(t_specifier *specif, void **data, va_list ap)
{
	static int (*const dispatch_table[128])(t_specifier *, void **, va_list) = {
		['c'] = &data_specifier_c,
		['s'] = &data_specifier_s,
		['i'] = &data_specifier_i,
		['d'] = &data_specifier_i,
		['x'] = &data_specifier_u,
		['X'] = &data_specifier_u,
		['o'] = &data_specifier_u,
		['u'] = &data_specifier_u,
		['f'] = &data_specifier_f,
		['p'] = &data_specifier_p,
		['%'] = &data_specifier_pc,
		['b'] = &data_specifier_i,
	};

	if (dispatch_table[specif->formatid])
		return (dispatch_table[specif->formatid](specif, data, ap));
	else
		return ((errno = ENOTSUP));
}
