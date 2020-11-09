/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:02:14 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 10:51:04 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static t_output		g_output = { .mode=T_FILE, .dest={1}, .max_size={0, 0} };
static char			g_buffer[BUFFER_SIZE];
static size_t		g_inbuffer;
static size_t		g_nprinted;

void		set_output(t_mode mode, t_dest dest, t_opt max_size)
{
	g_output = (t_output){mode, dest, max_size};
}

void		cleanup(void)
{
	g_inbuffer = 0;
	g_nprinted = 0;
	g_output = (t_output){T_FILE, (t_dest)1, (t_opt){0, 0}};
}

ssize_t		flush_buffer(void)
{
	if (g_output.mode == T_FILE)
		write(g_output.dest.fd, g_buffer, g_inbuffer);
	g_nprinted += g_inbuffer;
	g_inbuffer = 0;
	return (errno ? -1 : (ssize_t)g_nprinted);
}

int			pf_putchar(char c)
{
	if (g_output.mode == T_STRING)
	{
		if (!g_output.max_size.isgiven ||
			(size_t)g_output.max_size.val > g_nprinted + 1)
			g_output.dest.str[g_nprinted] = c;
		if (g_output.max_size.isgiven &&
			(size_t)g_output.max_size.val > g_nprinted)
			g_output.dest.str[g_nprinted + 1] = 0;
		g_nprinted++;
	}
	if (g_output.mode == T_FILE)
	{
		if (g_inbuffer == BUFFER_SIZE)
			flush_buffer();
		g_buffer[g_inbuffer++] = c;
	}
	return (0);
}
