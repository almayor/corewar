/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:17:40 by unite             #+#    #+#             */
/*   Updated: 2020/06/30 23:22:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

/*
** @ingroup ft_printf
** @brief Replicates behaviour of `vasprintf(3)`.
** @param[out] ret Pointer that will be set to a buffer sufficiently large to
** hold the formatted string. This pointer should be passed to `free(3)` to
** release the allocated storage when it is no longer needed.
** @param[in] format Format string that specifies how subsequent arguments
** are converted for output
** @param[in] ap A variable used by `stdarg(3)` to step through a list of
** variadic arguments.
** @return Number of characters printed or `-1` if an error occurs. Additionaly,
** in case of an error, `*ret` is set to be `NULL` and `errno` is set to
** `ENOMEM` (memory allocation error), `EINVAL` (invalid format placeholder
** specification), `ENOTSUP` (type field value not supported).
*/

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int		rc;
	int		size;
	va_list	ap_copy;

	*ret = 0;
	va_copy(ap_copy, ap);
	size = ft_vsnprintf(NULL, 0, format, ap_copy);
	va_end(ap_copy);
	if (size >= 0 &&
		(*ret = ft_calloc(sizeof(char), size + 1)) &&
		(rc = ft_vsprintf(*ret, format, ap)) >= 0)
		return (rc);
	else
	{
		free(*ret);
		return (-1);
	}
}
