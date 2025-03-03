/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_modules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 01:40:21 by user              #+#    #+#             */
/*   Updated: 2020/11/25 14:08:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"

void		int_writer(t_parser *stor, unsigned long data)
{
	union u_four	uni_data;
	unsigned char	c;

	uni_data.val = data;
	c = uni_data.t_fr.c4;
	if (write(stor->fd_cor, &c, 1) == -1)
		core_error(stor, WRITE_ERR, NULL, NULL);
	c = uni_data.t_fr.c3;
	if (write(stor->fd_cor, &c, 1) == -1)
		core_error(stor, WRITE_ERR, NULL, NULL);
	c = uni_data.t_fr.c2;
	if (write(stor->fd_cor, &c, 1) == -1)
		core_error(stor, WRITE_ERR, NULL, NULL);
	c = uni_data.t_fr.c1;
	if (write(stor->fd_cor, &c, 1) == -1)
		core_error(stor, WRITE_ERR, NULL, NULL);
}

void		short_writer(t_parser *stor, short data)
{
	union u_two		uni_data;
	unsigned char	c;

	uni_data.val = data;
	c = uni_data.t_tw.c2;
	if (write(stor->fd_cor, &c, 1) == -1)
		core_error(stor, WRITE_ERR, NULL, NULL);
	c = uni_data.t_tw.c1;
	if (write(stor->fd_cor, &c, 1) == -1)
		core_error(stor, WRITE_ERR, NULL, NULL);
}

int			byte_writer(t_parser *stor, unsigned char c)
{
	if (write(stor->fd_cor, &c, 1) == -1)
		core_error(stor, WRITE_ERR, NULL, NULL);
	return (1);
}

void		write_name_or_comment(t_parser *stor, int len, int kind)
{
	char			*data;
	unsigned char	c;
	int				i;

	data = kind == NAME_FLAG ? stor->name : stor->comment;
	i = 0;
	while (data[i])
	{
		c = data[i];
		if (write(stor->fd_cor, &c, 1) == -1)
			core_error(stor, WRITE_ERR, NULL, NULL);
		i++;
	}
	c = 0;
	while (i < len)
	{
		if (write(stor->fd_cor, &c, 1) == -1)
			core_error(stor, WRITE_ERR, NULL, NULL);
		i++;
	}
	int_writer(stor, 0);
}
