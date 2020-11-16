/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enrich_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:46:36 by user              #+#    #+#             */
/*   Updated: 2020/11/16 22:47:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_struct.h"
#include "translation.h"

int			op_reg(t_parser *stor, t_token *token, int name)
{
	token->op_code = op_tmpl[name].op_code;
	token->dir_size = op_tmpl[name].dir_size;
	token->is_arg_code = op_tmpl[name].is_arg_code;
	token->arg_code = 1 << 6;
	token->size = (OP_SIZE_BYTE + 1 + token->is_arg_code);
	stor->code_total_size += token->size;
	return (2);
}

int			op_dir(t_parser *stor, t_token *token, int name)
{
	token->op_code = op_tmpl[name].op_code;
	token->is_arg_code = op_tmpl[name].is_arg_code;
	token->dir_size = op_tmpl[name].dir_size;
	token->next->dir_size = token->dir_size;

	token->size = OP_SIZE_BYTE + op_tmpl[name].dir_size;
	stor->code_total_size += token->size;
	return (2);
}

int			op_reg_reg_reg(t_parser *stor, t_token *token, int name)
{
	token->op_code = op_tmpl[name].op_code;
	token->dir_size = op_tmpl[name].dir_size;
	token->is_arg_code = op_tmpl[name].is_arg_code;
	token->arg_code = (1 << 6) || (1 << 4) || (1 << 2);
	token->size += (OP_SIZE_BYTE + 3 + token->is_arg_code);
	stor->code_total_size += token->size;
	return (4);
}

int			op_three_args(t_parser *stor, t_token *token, int name)
{
	unsigned char arg1;
	unsigned char arg2;
	unsigned char arg3;

	token->op_code = op_tmpl[name].op_code;
	token->dir_size = op_tmpl[name].dir_size;
	arg1 = prepare_arg(stor, get_token(token, 1), name, 6);
	arg2 = prepare_arg(stor, get_token(token, 2), name, 4);
	arg3 = prepare_arg(stor, get_token(token, 3), name, 2);
	token->is_arg_code = op_tmpl[name].is_arg_code;
	token->arg_code = arg1 | arg2 | arg3;
	token->size += (OP_SIZE_BYTE + token->is_arg_code);
	stor->code_total_size += token->size;
	return (4);
}

int			op_two_args(t_parser *stor, t_token *token, int name)
{
	unsigned char arg1;
	unsigned char arg2;

	token->op_code = op_tmpl[name].op_code;
	token->dir_size = op_tmpl[name].dir_size;
	arg1 = prepare_arg(stor, get_token(token, 1), name, 6);
	arg2 = prepare_arg(stor, get_token(token, 2), name, 4);
	token->is_arg_code = op_tmpl[name].is_arg_code;
	token->arg_code = arg1 | arg2;
	token->size += (OP_SIZE_BYTE + token->is_arg_code);
	stor->code_total_size += token->size;
	return (3);
}

int			enrich_line(t_parser *stor, t_token *token)
{
	int		len;

	len = 0;
	while (token->type != OP_TYPE)
		token = token->next;
	stor->tokens = token;
	!ft_strcmp(token->content, op_tmpl[LIVE].name) ? (len = op_dir(stor, token, LIVE)) : 0;
	!ft_strcmp(token->content, op_tmpl[LD].name) ? (len = op_two_args(stor, token, LD)) : 0;
	!ft_strcmp(token->content, op_tmpl[ST].name) ? (len = op_two_args(stor, token, ST)) : 0;
	!ft_strcmp(token->content, op_tmpl[ADD].name) ? (len = op_reg_reg_reg(stor, token, ADD)) : 0;
	!ft_strcmp(token->content, op_tmpl[SUB].name) ? (len = op_reg_reg_reg(stor, token, SUB)) : 0;
	!ft_strcmp(token->content, op_tmpl[AND].name) ? (len = op_three_args(stor, token, AND)) : 0;
	!ft_strcmp(token->content, op_tmpl[OR].name) ? (len = op_three_args(stor, token, OR)) : 0;
	!ft_strcmp(token->content, op_tmpl[XOR].name) ? (len = op_three_args(stor, token, XOR)) : 0;
	!ft_strcmp(token->content, op_tmpl[ZJMP].name) ? (len = op_dir(stor, token, ZJMP)) : 0;
	!ft_strcmp(token->content, op_tmpl[LDI].name) ? (len = op_three_args(stor, token, LDI)) : 0;
	!ft_strcmp(token->content, op_tmpl[STI].name) ? (len = op_three_args(stor, token, STI)) : 0;
	!ft_strcmp(token->content, op_tmpl[FORK].name) ? (len = op_dir(stor, token, FORK)) : 0;
	!ft_strcmp(token->content, op_tmpl[LLD].name) ? (len = op_two_args(stor, token, LLD)) : 0;
	!ft_strcmp(token->content, op_tmpl[LLDI].name) ? (len = op_two_args(stor, token, LLDI)) : 0;
	!ft_strcmp(token->content, op_tmpl[LFORK].name) ? (len = op_dir(stor, token, LFORK)) : 0;
	!ft_strcmp(token->content, op_tmpl[AFF].name) ? (len = op_reg(stor, token, AFF)) : 0;
	return (len);
}
