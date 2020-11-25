/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 14:17:47 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

/*
** @ingroup ft_printf
** @brief Replicates behaviour of `snprintf(3)`.
** @param[in] str String where to print output.
** @param[in] size Size of the string (at most `size - 1` characters are
** printed and, unless `size` is `0`, the string is always null-terminated).
** @param[in] format Format string that specifies how subsequent arguments
** are converted for output
** @param[in] ... Variadic arguments
** @return Number of characters printed if `size` were unlimited (not
** including the final `\0`) or `-1` if an error occurs. Additionaly,
** in case of an error, `errno` is set to `ENOMEM` (memory allocation error),
** `EINVAL` (invalid format placeholder specification), `ENOTSUP` (type field
** value not supported).
*/

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	ap;
	int		rc;

	va_start(ap, format);
	rc = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (rc);
}
