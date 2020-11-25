/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enrich_latest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:56:44 by user              #+#    #+#             */
/*   Updated: 2020/11/17 15:01:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*	for check OP_ARGS

	t_token 		*args[op_tmpl[name].args_num];

	args[ct] = get_token(token, ct + 1);
	
	
	ct = 0;
	printf("\ncontent = %s, y = %d x = %d\n", token->content, token->point.row, token->point.token);
	while (ct < token->num_args)
	{
		printf("elem = %d content = %s, y = %d x = %d\n", ct, args[ct]->content, args[ct]->point.row, args[ct]->point.token);
		ct++;
	}
	printf("is = %d arg_code = %#x\n", token->is_arg_code, token->arg_code);

*/


// int			op_reg(t_parser *stor, t_token *token, int name)
// {
// 	token->op_code = op_tmpl[name].op_code;
// 	token->num_args = op_tmpl[name].args_num;
// 	token->dir_size = op_tmpl[name].dir_size;
// 	token->is_arg_code = op_tmpl[name].is_arg_code;

// 	token->arg_code = 1 << 6;
// 	token->size = (OP_SIZE_BYTE + 1 + token->is_arg_code);
// 	stor->code_total_size += token->size;
// 	return (2);
// }

// int			op_dir(t_parser *stor, t_token *token, int name)
// {
// 	token->op_code = op_tmpl[name].op_code;
// 	token->num_args = op_tmpl[name].args_num;
// 	token->is_arg_code = op_tmpl[name].is_arg_code;
// 	token->dir_size = op_tmpl[name].dir_size;

// 	token->next->dir_size = token->dir_size;
// 	token->size = OP_SIZE_BYTE + op_tmpl[name].dir_size;
// 	stor->code_total_size += token->size;
// 	return (2);
// }

// int			op_three_args(t_parser *stor, t_token *token, int name)
// {
// 	unsigned char arg1;
// 	unsigned char arg2;
// 	unsigned char arg3;

// 	t_token 	*args[3];

// 	token->op_code = op_tmpl[name].op_code;
// 	token->num_args = op_tmpl[name].args_num;
// 	token->dir_size = op_tmpl[name].dir_size;
// 	arg1 = prepare_arg(stor, get_token(token, 1), name, 6);
// 	arg2 = prepare_arg(stor, get_token(token, 2), name, 4);
// 	arg3 = prepare_arg(stor, get_token(token, 3), name, 2);
// 	token->is_arg_code = op_tmpl[name].is_arg_code;
// 	token->arg_code = arg1 | arg2 | arg3;
// 	token->size += (OP_SIZE_BYTE + token->is_arg_code);
// 	stor->code_total_size += token->size;
// 	return (4);
// }

// int			op_two_args(t_parser *stor, t_token *token, int name)
// {
// 	unsigned char arg1;
// 	unsigned char arg2;

// 	token->op_code = op_tmpl[name].op_code;
// 	token->num_args = op_tmpl[name].args_num;
// 	token->dir_size = op_tmpl[name].dir_size;
// 	arg1 = prepare_arg(stor, get_token(token, 1), name, 6);
// 	arg2 = prepare_arg(stor, get_token(token, 2), name, 4);
// 	token->is_arg_code = op_tmpl[name].is_arg_code;
// 	token->arg_code = arg1 | arg2;
// 	token->size += (OP_SIZE_BYTE + token->is_arg_code);
// 	stor->code_total_size += token->size;
// 	return (3);
// }


// int			enrich_row(t_parser *stor, t_token *tk)
// {
// 	int		len;

// 	len = 0;
// 	while (tk->type != OP_TYPE)
// 		tk = tk->next;
// 	stor->tokens = tk;

// 	!ft_strcmp(tk->content, op_tmpl[LIVE].name) ? (len = op_dir(stor, tk, LIVE)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[LD].name) ? (len = op_two_args(stor, tk, LD)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[ST].name) ? (len = op_two_args(stor, tk, ST)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[ADD].name) ? (len = op_three_args(stor, tk, ADD)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[SUB].name) ? (len = op_three_args(stor, tk, SUB)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[AND].name) ? (len = op_three_args(stor, tk, AND)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[OR].name) ? (len = op_three_args(stor, tk, OR)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[XOR].name) ? (len = op_three_args(stor, tk, XOR)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[ZJMP].name) ? (len = op_dir(stor, tk, ZJMP)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[LDI].name) ? (len = op_three_args(stor, tk, LDI)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[STI].name) ? (len = op_three_args(stor, tk, STI)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[FORK].name) ? (len = op_dir(stor, tk, FORK)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[LLD].name) ? (len = op_two_args(stor, tk, LLD)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[LLDI].name) ? (len = op_two_args(stor, tk, LLDI)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[LFORK].name) ? (len = op_dir(stor, tk, LFORK)) : 0;
// 	!ft_strcmp(tk->content, op_tmpl[AFF].name) ? (len = op_reg(stor, tk, AFF)) : 0;
// 	return (len);
// }