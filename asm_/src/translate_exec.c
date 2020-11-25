/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:33:01 by user              #+#    #+#             */
/*   Updated: 2020/11/25 14:07:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"

void		translate_arg(t_parser *stor, t_token *token, int size)
{
	if (token->type == REG_ARG_TYPE)
		byte_writer(stor, (unsigned char)ft_atoi(token->content + 1));
	else if (token->type == DIR_ARG_TYPE)
	{
		if (token->dir_size == 4)
			int_writer(stor, ft_atoi_long(token->content));
		else if (token->dir_size == 2)
			short_writer(stor, (short)ft_atoi(token->content));
	}
	else if (token->type == DIR_LABL_ARG_TYPE)
	{
		if (token->dir_size == 4)
			int_writer(stor, find_label_value(stor, token, size));
		else if (token->dir_size == 2)
			short_writer(stor, (short)find_label_value(stor, token, size));
	}
	else if (token->type == IND_ARG_TYPE)
		short_writer(stor, (short)ft_atoi(token->content));
	else if (token->type == IND_LABL_ARG_TYPE)
		short_writer(stor, (short)find_label_value(stor, token, size));
}

int			translate_exec_row(t_parser *stor, t_token *token)
{
	int		ct;

	ct = 0;
	while (token->type != OP_TYPE)
	{
		if (token->type == END_FILE)
		{
			stor->tokens = token;
			return (0);
		}
		token = token->next;
	}
	stor->tokens = token;
	if (token->type == OP_TYPE && (byte_writer(stor, token->op_code)))
		token->is_arg_code ? byte_writer(stor, token->arg_code) : 0;
	while (++ct <= token->num_args)
		translate_arg(stor, get_token(token, ct), token->size);
	return (token->num_args + 1);
}

void		translate_exec_code(t_parser *stor)
{
	int		len;

	len = 0;
	while (stor->tokens && stor->tokens->type != END_FILE)
	{
		len = translate_exec_row(stor, stor->tokens);
		stor->tokens = get_token(stor->tokens, len);
	}
	stor->tokens = stor->tokens_head;
}
