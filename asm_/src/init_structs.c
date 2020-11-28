/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:40:47 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/21 02:05:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_label		*init_label(char *content, int row_num, int token_num,
t_parser *parser)
{
	t_label	*label;

	if (!(label = ft_calloc(1, sizeof(t_label))))
		core_error(parser, ERR_LABEL_INIT, NULL, NULL);
	if (!(label->content = ft_strdup(content)))
		core_error(parser, ERR_STR_INIT, NULL, NULL);
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

	if (!(token = ft_calloc(1, sizeof(t_token))))
		core_error(parser, ERR_TOKEN_INIT, NULL, NULL);
	token->type = type;
	token->point = init_point();
	token->point.row = parser->point.row;
	if (parser->comma > 1)
		core_error(parser, ERR_COMMA, NULL, NULL);
	parser->comma = 0;
	return (token);
}

t_parser	*init_asm_parser(void)
{
	t_parser	*parser;

	if (!(parser = ft_calloc(1, sizeof(t_parser))))
		core_error(parser, ERR_PARSER_INIT, NULL, NULL);
	parser->point = init_point();
	parser->tokens_head = parser->tokens;
	return (parser);
}
