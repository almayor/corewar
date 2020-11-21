/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enrich_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:46:36 by user              #+#    #+#             */
/*   Updated: 2020/11/21 21:07:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "translation.h"
#include "operations.h"

t_token		*get_token(t_token *token, int len)
{
	int	name;

	name = token->name;
	while (len)
	{
		token = token->next;
		len--;
	}
	token->name = name;
	return (token);
}

void		check_arg(t_parser *stor, t_token *arg, int shift)
{
	int		pos;
	int		expected_code;
	int		max_args;
	int		code;

	pos = (OCTET - shift) / 2;
	expected_code = g_op_tmpl[arg->name].args_types[pos - 1];
	max_args = g_op_tmpl[arg->name].args_num;
	code = arg->type;
	code -= (code == DIR_LABL_ARG_TYPE || code == IND_LABL_ARG_TYPE) ? 1 : 0;
	if ((pos > max_args || arg->type == LABEL_TYPE || arg->type == OP_TYPE) ||
	(pos == max_args && arg->next && (arg->next->type != LABEL_TYPE &&
	arg->next->type != OP_TYPE && arg->next->type != END_FILE)) ||
	(pos < max_args && arg->next && arg->next->type == END_FILE))
		core_error(stor, ARG_NUM_ERR, *put_op_usage, arg);
	if (expected_code < (T_REG | T_DIR | T_IND) && !(expected_code & code))
		core_error(stor, ARG_TYPE_ERR, *put_op_usage, arg);
	if ((arg->type == DIR_LABL_ARG_TYPE || arg->type == IND_LABL_ARG_TYPE) &&
		!get_label(stor, arg->content))
		core_error(stor, LABEL_ERR, *put_label_err, arg);
}

int			get_arg(t_parser *stor, t_token *arg, int shift)
{
	int		dir_size;
	int		arg_code;

	arg_code = 0;
	dir_size = g_op_tmpl[arg->name].dir_size;
	check_arg(stor, arg, shift);
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
		core_error(stor, ENRICH_ERR, NULL, NULL);
	token->op_code = g_op_tmpl[name].op_code;
	token->is_arg_code = g_op_tmpl[name].is_arg_code;
	token->num_args = g_op_tmpl[name].args_num;
	token->dir_size = g_op_tmpl[name].dir_size;
	token->name = name;
	ct = -1;
	while (++ct < token->num_args)
		args[ct] = get_arg(stor, get_token(token, ct + 1), (3 - ct) * 2);
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
	while (token && token->type != OP_TYPE)
		token = token->next;
	stor->tokens = token;
	while (++ind <= 15)
		if (token && !ft_strcmp(token->content, g_op_tmpl[ind].name))
			break ;
	return (op_args(stor, token, ind));
}
