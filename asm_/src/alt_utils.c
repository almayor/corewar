/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:44:08 by user              #+#    #+#             */
/*   Updated: 2020/12/01 09:55:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alt_parser.h"
#include "translation.h"

void		command_err(t_token *arg, t_parser *stor)
{
	int		len;
	int		pos;

	len = 0;
	pos = stor->x_read;
	if (arg)
		return ;
	while (stor->l[pos] != '\n')
	{
		pos++;
		len++;
	}
	write(2, "content: ", 9);
	write(2, &stor->l[stor->x_read], len + 1);
}

void		lexical_err(t_token *arg, t_parser *stor)
{
	int		len;
	int		pos;

	if (arg)
		return ;
	len = 0;
	pos = stor->x_read;
	while (stor->l[pos] != '\n')
	{
		pos++;
		len++;
	}
	ft_printf("row %d, symbol %d\n", stor->y_read, stor->x_read);
	write(2, "content: ", 9);
	write(2, &stor->l[stor->x_read], len + 1);
}

void		skip_spaces(t_parser *stor)
{
	printf("skip 1\n");
	while (ft_iswspace(stor->l[stor->x_read]))
		stor->x_read++;
	if (is_comment(stor->l[stor->x_read]))
	{
		while (stor->l[stor->x_read] != '\n')
			stor->x_read++;
		stor->x_read++;
	}
	printf("skip 2\n");
	printf("after skip = %c\n", stor->l[stor->x_read]);
}
