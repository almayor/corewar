/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 23:21:49 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

/*
** @ingroup ft_printf
** @brief Replicates behaviour of `asprintf(3)`.
** @param[out] ret Pointer that will be set to a buffer sufficiently large to
** hold the formatted string. This pointer should be passed to `free(3)` to
** release the allocated storage when it is no longer needed.
** @param[in] format Format string that specifies how subsequent arguments
** are converted for output
** @param[in] ... Variadic arguments
** @return Number of characters printed or `-1` if an error occurs. Additionaly,
** in case of an error, `*ret` is set to be `NULL` and `errno` is set to
** `ENOMEM` (memory allocation error), `EINVAL` (invalid format placeholder
** specification), `ENOTSUP` (type field value not supported).
*/

int	ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		rc;

	va_start(ap, format);
	rc = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (rc);
}
