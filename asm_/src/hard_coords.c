/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:40:47 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/21 02:05:07 by user             ###   ########.fr       */
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

int			hard_coord3(t_parser *parser, t_token **token,
int c, int tok_num)
{
	if ((*token)->type == LABEL_TYPE && (*token)->next->type == END_FILE)
		c = 0;
	(*token)->point.token = tok_num;
	if ((*token)->type == LABEL_TYPE)
		add_label(&parser->labels,
		init_label((*token)->content, (*token)->point.row, c, parser));
	return (tok_num);
}

int			hard_coord(t_parser *parser, t_token **token, int tok_num, int c)
{
	t_token	*check;
	int		a;

	check = *token;
	c = hard_coord2(check, c);
	while (1)
	{
		a = (*token)->point.row;
		(*token)->point.row = check->next->point.row;
		tok_num = hard_coord3(parser, token, c, tok_num + 1);
		if ((*token)->next->type == END_FILE)
			break ;
		if (((*token)->next->type != LABEL_TYPE &&
		(*token)->next->type != OP_TYPE))
			c = -2;
		if (c == -2 && (((*token)->next->point.row != a) ||
		(((*token)->next->type == LABEL_TYPE ||
		(*token)->next->type == OP_TYPE || (*token)->next->type == END_FILE))))
			break ;
		(*token) = (*token)->next;
	}
	if ((*token)->next && a == (*token)->next->point.row)
		core_error(parser, ERR_OPS, NULL, NULL);
	return (tok_num);
}
