/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:00:33 by unite             #+#    #+#             */
/*   Updated: 2020/06/29 17:05:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	print_specifier(t_specifier *specif, void *data)
{
	static int		(*const dispatch_table[128])(t_specifier *, void *) = {
		['c'] = &print_specifier_c,
		['s'] = &print_specifier_s,
		['i'] = &print_specifier_i,
		['d'] = &print_specifier_i,
		['x'] = &print_specifier_x,
		['X'] = &print_specifier_xx,
		['o'] = &print_specifier_o,
		['u'] = &print_specifier_u,
		['f'] = &print_specifier_f,
		['p'] = &print_specifier_p,
		['%'] = &print_specifier_c,
		['b'] = &print_specifier_b
	};

	if (dispatch_table[specif->formatid])
		return (dispatch_table[specif->formatid](specif, data));
	else
		return ((errno = ENOTSUP));
}
