/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enrich_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:46:36 by user              #+#    #+#             */
/*   Updated: 2020/11/18 20:39:48 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"
#include "operations.h"

t_token		*get_token(t_token *token, int len)
{
	while (len)
	{
		token = token->next;
		len--;
	}
	return (token);
}

int			get_arg(t_parser *stor, t_token *arg, int name, int shift)
{
	int		dir_size;
	int		arg_code;

	arg_code = 0;
	dir_size = op_tmpl[name].dir_size;
	if (arg->type == REG_ARG_TYPE)
	{
		arg_code = REG_CODE;
		stor->tokens->size += 1;
	}
	else if (arg->type == DIR_ARG_TYPE || arg->type == DIR_LABL_ARG_TYPE)
	{
		arg_code = DIR_CODE;
		arg->dir_size = dir_size;
		stor->tokens->size += dir_size;
	}
	else
	{
		arg_code = IND_CODE;
		stor->tokens->size += 2;
	}
	return (arg_code << shift);
}

int			op_args(t_parser *stor, t_token *token, int name)
{
	unsigned char	args[3];
	int				ct;

	if (!token)
		core_error(stor, ENRICH_ERR);
	token->op_code = op_tmpl[name].op_code;
	token->is_arg_code = op_tmpl[name].is_arg_code;
	token->num_args = op_tmpl[name].args_num;
	token->dir_size = op_tmpl[name].dir_size;
	ct = -1;
	while (++ct < token->num_args)
		args[ct] = get_arg(stor, get_token(token, ct + 1), name, (3 - ct) * 2);
	ct = 0;
	token->arg_code = args[0];
	while (++ct < token->num_args)
		token->arg_code |= args[ct];
	token->size += (OP_SIZE_BYTE + token->is_arg_code);
	stor->code_total_size += token->size;
	return (token->num_args + 1);
}

int			enrich_row(t_parser *stor, t_token *token)
{
	int		ind;

	ind = -1;
	while (token->type != OP_TYPE)
		token = token->next;
	stor->tokens = token;
	while (++ind <= 15)
		if (!ft_strcmp(token->content, op_tmpl[ind].name))
			break ;
	return (op_args(stor, token, ind));
}

void		enrich_data(t_parser *stor)
{
	int		len;

	len = 0;
	while (stor->tokens && stor->tokens->type != END_FILE)
	{
		len = enrich_row(stor, stor->tokens);
		stor->tokens = get_token(stor->tokens, len);
	}
	stor->tokens = stor->tokens_head;
}
