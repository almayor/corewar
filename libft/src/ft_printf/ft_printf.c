/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/05/18 03:37:39 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

/*
** @ingroup ft_printf
** @brief Replicates behaviour of `printf(3)`.
** @param[in] format Format string that specifies how subsequent arguments
** are converted for output
** @param[in] ... Variadic arguments
** @return Number of characters printed or `-1` if an error occurs. Additionaly,
** in case of an error, `errno` is set to `ENOMEM` (memory allocation error),
** `EINVAL` (invalid format placeholder specification), `ENOTSUP` (type field
** value not supported) or other values set by `write(2)`.
*/

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rc;

	va_start(ap, format);
	rc = ft_vprintf(format, ap);
	va_end(ap);
	return (rc);
}
