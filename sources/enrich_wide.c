/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enrich_wide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:26:59 by user              #+#    #+#             */
/*   Updated: 2020/11/16 22:41:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_struct.h"
#include "translation.h"

/* OLD VERSION of fill exec_code_size

# define EXEC_CODE_SIZE_MOCK 39321

	int_writer(stor, EXEC_CODE_SIZE_MOCK); // fill exec_code_size with "9999". Rewrite it after put all ops and calc actual exec_code_size.
	lseek(stor->fd_cor, 4 + PROG_NAME_LENGTH + 4, SEEK_SET);
*/


// int			op_dirind_reg(t_parser *stor, t_token *token, int name)
// {
// 	unsigned char arg1;
// 	unsigned char arg2;

// 	token->op_code = op_tmpl[name].op_code;
// 	arg1 = prepare_arg(stor, get_token(token, 1), name, 6);
// 	arg2 = prepare_arg(stor, get_token(token, 2), name, 4);
// 	token->is_arg_code = op_tmpl[name].is_arg_code;
// 	token->arg_code = arg1 | arg2;
// 	token->size += OP_SIZE_BYTE;
// 	stor->code_total_size += token->size;
// 	return (3);
// }

// int			op_reg_regind(t_parser *stor, t_token *token, int name)
// {
// 	unsigned char arg1;
// 	unsigned char arg2;

// 	token->op_code = op_tmpl[name].op_code;
// 	arg1 = prepare_arg(stor, get_token(token, 1), name, 6);
// 	arg2 = prepare_arg(stor, get_token(token, 2), name, 4);
// 	token->is_arg_code = op_tmpl[name].is_arg_code;
// 	token->arg_code = arg1 | arg2;
// 	token->size += OP_SIZE_BYTE;
// 	stor->code_total_size += token->size;
// 	return (3);
// }

// int			op_regdirind_regdirind_reg(t_parser *stor, t_token *token, int name)
// {
// 	unsigned char arg1;
// 	unsigned char arg2;
// 	unsigned char arg3;

// 	token->op_code = op_tmpl[name].op_code;
// 	arg1 = prepare_arg(stor, get_token(token, 1), name, 6);
// 	arg2 = prepare_arg(stor, get_token(token, 2), name, 4);
// 	arg3 = prepare_arg(stor, get_token(token, 3), name, 2);
// 	token->is_arg_code = op_tmpl[name].is_arg_code;
// 	token->arg_code = arg1 | arg2 | arg3;
// 	token->size += OP_SIZE_BYTE;
// 	stor->code_total_size += token->size;
// 	return (4);
// }

// int			op_regdirind_regdir_reg(t_parser *stor, t_token *token, int name)
// {
// 	unsigned char arg1;
// 	unsigned char arg2;
// 	unsigned char arg3;

// 	token->op_code = op_tmpl[name].op_code;
// 	arg1 = prepare_arg(stor, get_token(token, 1), name, 6);
// 	arg2 = prepare_arg(stor, get_token(token, 2), name, 4);
// 	arg3 = prepare_arg(stor, get_token(token, 3), name, 2);
// 	token->is_arg_code = op_tmpl[name].is_arg_code;
// 	token->arg_code = arg1 | arg2 | arg3;
// 	token->size += OP_SIZE_BYTE;
// 	stor->code_total_size += token->size;
// 	return (4);
// }


// int			op_reg_regdirint_regdir(t_parser *stor, t_token *token, int name);


// int			enrich_line_wide(t_parser *stor, t_token *token)
// {
// 	int		len;

// 	len = 0;
// 	while (token->type == LABEL_TYPE && len++)
// 		token = token->next;
// 	!ft_strcmp(token->content, op_tmpl[LIVE].name) ? (len += op_dir(stor, token, LIVE)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[LD].name) ? (len += op_dirind_reg(stor, token, LD)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[ST].name) ? (len += op_reg_regind(stor, token, ST)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[ADD].name) ? (len += op_reg_reg_reg(stor, token, ADD)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[SUB].name) ? (len += op_reg_reg_reg(stor, token, SUB)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[AND].name) ? (len += op_regdirind_regdirind_reg(stor, token, AND)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[OR].name) ? (len += op_regdirind_regdirind_reg(stor, token, OR)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[XOR].name) ? (len += op_regdirind_regdirind_reg(stor, token, XOR)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[ZJMP].name) ? (len += op_dir(stor, token, ZJMP)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[LDI].name) ? (len += op_regdirind_regdir_reg(stor, token, LDI)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[STI].name) ? (len += op_reg_regdirint_regdir(stor, token, STI)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[FORK].name) ? (len += op_dir(stor, token, FORK)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[LLD].name) ? (len += op_dirind_reg(stor, token, LLD)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[LLDI].name) ? (len += op_dirind_reg(stor, token, LLDI)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[LFORK].name) ? (len += op_dir(stor, token, LFORK)) : 0;
// 	!ft_strcmp(token->content, op_tmpl[AFF].name) ? (len += op_reg(stor, token, AFF)) : 0;
// 	return (len);
// }