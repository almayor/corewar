/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:40:47 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/09 13:40:50 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
t_label		*init_label(char *name, int op_pos)
{
	t_label	*label;

	if (!(label = (t_label *)malloc(sizeof(t_label))))
		terminate(ERR_LABEL_INIT);
	if (!(label->name = ft_strdup(name)))
		terminate(ERR_STR_INIT);
	label->op_pos = op_pos;
	label->mentions = NULL;
	label->next = NULL;
	return (label);
} 

t_mention	*init_mention(t_parser *parser, t_token *token, size_t size)
{
	t_mention	*mention;

	if (!(mention = (t_mention *)malloc(sizeof(t_mention))))
		terminate(ERR_MENTION_INIT);
	mention->row = token->row;
	mention->column = token->column;
	mention->pos = parser->pos;
	mention->op_pos = parser->op_pos;
	mention->size = size;
	mention->next = NULL;
	return (mention);
}
*/

t_token		*init_token(t_parser *parser, t_type type)
{
	t_token	*token;

	if (!(token = (t_token *)malloc(sizeof(t_token))))
		terminate(ERR_TOKEN_INIT);
	token->content = NULL;
	token->type = type;
	token->x = parser->x_read;
	if (type == SEPARATOR || type == NEW_LINE)
		token->y = parser->y_read - 1;
	else
		token->y = parser->y_read;
	token->next = NULL;
	return (token);
}

t_parser	*init_asm_parser(void)
{
    t_parser	*parser;

	if (!(parser = (t_parser *)malloc(sizeof(t_parser))))
		terminate(ERR_PARSER_INIT);
	parser->x_read = 0;
	parser->y_read = 0;
	parser->x_write = 0;
	parser->y_write = 0;
	parser->name = NULL;
	parser->comment = NULL;
	parser->code = NULL;
	parser->code_size = 0;
	parser->labels = NULL;
	parser->tokens = NULL;
    return (parser);
}
