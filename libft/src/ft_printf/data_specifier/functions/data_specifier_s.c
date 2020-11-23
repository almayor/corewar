/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_specifier_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:04:01 by unite             #+#    #+#             */
/*   Updated: 2020/06/29 17:04:10 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int	data_specifier_s(t_specifier *specif, void **data, va_list ap)
{
	static char	*null_str = "(null)";

	(void)specif;
	if (!(*data = malloc(sizeof(char *))))
		return ((errno = ENOMEM));
	if (!(*(char **)*data = va_arg(ap, char *)))
		*(char **)*data = null_str;
	return (0);
}
