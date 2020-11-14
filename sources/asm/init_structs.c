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
t_point		*init_point(void)
{
    t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		terminate(ERR_POINT_INIT);
	point->x = 0;
	point->y = 0;
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
	token->point->x = parser->point->x;
	token->point->y = parser->point->y;
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
	parser->fd_cor = 0;
	parser->fd_s = 0;
	parser->code_total_size = 0;
	parser->name = NULL;
	parser->file_name = NULL;
	parser->comment = NULL;
    return (parser);
}

