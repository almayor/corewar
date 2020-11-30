/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:44:40 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/24 21:34:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			hard_coord2(t_token *check, int c)
{
	while (check->type == LABEL_TYPE)
	{
		check = check->next;
		c++;
	}
	return (c);
}

int			hard_coord(t_parser *parser, t_token **token, int tok_num, int c)
{
	t_token	*check;

	check = *token;
	c = hard_coord2(check, c);
	while ((*token)->type != END_FILE)
	{
		tok_num++;
		(*token)->point.token = tok_num;
		(*token)->point.row = check->next->point.row;
		if ((*token)->type == LABEL_TYPE && (*token)->next->type == END_FILE)
			c = 0;
		if ((*token)->type == LABEL_TYPE)
			add_label(&parser->labels,
			init_label((*token)->content, (*token)->point.row, c, parser));
		if ((*token)->type != LABEL_TYPE && (*token)->type != OP_TYPE)
			c = -2;
		else if (c == -2 && (*token)->next->point.row != ((*token)->point.row))
			break ;
		if (c == -2 && ((*token)->next->type == LABEL_TYPE ||
		(*token)->next->type == OP_TYPE || (*token)->next->type == END_FILE))
			break ;
		(*token) = (*token)->next;
	}
	return (tok_num);
}

int			tok_num_padding(int tok_num, t_token *token)
{
	tok_num++;
	token->point.token = tok_num;
	return (tok_num);
}

int			coords_and_labels2(t_parser *parser, t_token **token, int tok_num)
{
	tok_num = tok_num_padding(tok_num, (*token));
	if ((*token)->type == LABEL_TYPE)
		add_label(&parser->labels,
		init_label((*token)->content, (*token)->point.row,
		(*token)->point.token + 1, parser));
	return (tok_num);
}

void		coords_and_labels(t_parser *parser, t_token *tokens, int tok_num)
{
	int		y;
	t_token	*token;

	token = tokens;
	y = 0;
	while (token)
	{
		if (token->type == LABEL_TYPE)
			validate_labeltoken(token, parser);
		if (token->type == LABEL_TYPE && token->point.row != y)
			tok_num = hard_coord(parser, &token, -1, 0);
		else if (y != token->point.row)
			tok_num = coords_and_labels2(parser, &token, -1);
		else
			tok_num = coords_and_labels2(parser, &token, tok_num);
		y = token->point.row;
		token = token->next;
	}
	validate_tokens(parser, parser->tokens, 0, 0);
}
