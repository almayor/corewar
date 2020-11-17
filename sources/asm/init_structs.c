/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:40:47 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/16 22:15:30 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*init_label(char *content, int row_num, int token_num)
{
	t_label	*label;

	if (!(label = (t_label *)malloc(sizeof(t_label))))
		terminate(ERR_LABEL_INIT);
	if (!(label->content = ft_strdup(content)))
		terminate(ERR_STR_INIT);
	label->next = NULL;
	label->point.row = row_num;
	label->point.token = token_num;
	return (label);
}

t_point		init_point(void)
{
	t_point	point;

	point.row = 0;
	point.token = 0;
	return (point);
}

t_token		*init_token(t_parser *parser, t_type type)
{
	t_token	*token;

	if (!(token = (t_token *)malloc(sizeof(t_token))))
		terminate(ERR_TOKEN_INIT);
	token->type = type;
	token->content = NULL;
	token->point = init_point();
	token->point.row = parser->point.row;
	token->size = 0;
	token->op_code = NULL;
	token->is_arg_code = 0;
	token->arg_code = NULL;
	token->dir_size = 0;
	token->next = NULL;
	return (token);
}

t_parser	*init_asm_parser(void)
{
	t_parser	*parser;

	if (!(parser = (t_parser *)malloc(sizeof(t_parser))))
		terminate(ERR_PARSER_INIT);
	parser->point = init_point();
	parser->tokens = NULL;
	parser->labels = NULL;
	parser->x_read = 0;
	parser->fd_cor = 0;
	parser->fd_s = 0;
	parser->code_total_size = 0;
	parser->name = NULL;
	parser->file_name = NULL;
	parser->comment = NULL;
	return (parser);
}
