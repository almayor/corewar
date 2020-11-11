/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_modules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 01:40:21 by user              #+#    #+#             */
/*   Updated: 2020/11/12 02:32:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_struct.h"
#include "translation.h"

void		int_writer(t_parser *stor, unsigned int data)
{
	union u_four 	uni_data;
	unsigned char	c;

	uni_data.val = data;
	c = uni_data.t_fr.c4;
	write(stor->fd_cor, &c, 1);
	c = uni_data.t_fr.c3;
	write(stor->fd_cor, &c, 1);
	c = uni_data.t_fr.c2;
	write(stor->fd_cor, &c, 1);
	c = uni_data.t_fr.c1;
	write(stor->fd_cor, &c, 1);
}


void		string_writer(int fd, char *data, int len)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (data[i])
	{
		c = data[i];
		write(fd, &c, 1);
		i++;
	}
	c = 0;
	while (i < len)
	{
		write(fd, &c, 1);
		i++;
	}
}

void		write_name_or_comment(t_parser *stor, int len, int kind)
{
	char *data;

	data = kind == NAME_FLAG ? stor->name : stor->comment;
	string_writer(stor->fd_cor, data, len);
	int_writer(stor, 0);
}
