/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enrich_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:47:58 by user              #+#    #+#             */
/*   Updated: 2020/11/16 22:48:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_struct.h"
#include "translation.h"

t_token		*get_token(t_token *token, int len)
{
	while (len)
	{
		token = token->next;
		len--;
	}
	return (token);
}

int			prepare_arg(t_parser *stor, t_token *dst, int name, int shift)
{
	int 	dir_size;
	int 	arg;

	arg = 0;
	dir_size = op_tmpl[name].dir_size;
	if (dst->type == REG_ARG_TYPE)
	{
		arg = REG_CODE;
		stor->tokens->size += 1;
	}
	else if (dst->type == DIR_ARG_TYPE || dst->type == DIR_LABL_ARG_TYPE)
	{
		arg = DIR_CODE;
		dst->dir_size = dir_size;
		stor->tokens->size += dir_size;
	}
	else
	{
		arg = IND_CODE;
		stor->tokens->size += 2;
	}
	return (arg << shift);
}
