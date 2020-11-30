/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:21:04 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/21 02:08:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		validate_labeltoken(t_token *token, t_parser *parser)
{
	t_label *label;

	label = parser->labels;
	while (label)
	{
		if (!ft_strcmp(token->content, label->content))
		{
			token->type = UNKNOWN;
			while (token && (token->type != OP_TYPE &&
			token->type != LABEL_TYPE))
			{
				token->type = UNKNOWN;
				token = token->next;
			}
			break ;
		}
		label = label->next;
	}
}

void		prune_tokens(t_parser *parser)
{
	t_token *curr;
	t_token *prev;
	t_token *tmp;

	prev = parser->tokens;
	curr = parser->tokens->next;
	while (curr)
	{
		if (prev->next && prev->type == LABEL_TYPE &&
		!(prev->next->type == OP_TYPE || prev->next->type == LABEL_TYPE
		|| prev->next->type == END_FILE))
			core_error(parser, ERR_LABEL_OP, NULL, NULL);
		while (curr->next && curr->type == UNKNOWN)
		{
			tmp = curr;
			curr = curr->next;
			free(tmp->content);
			tmp->content = NULL;
			free(tmp);
			tmp = NULL;
			prev->next = curr;
		}
		curr = curr->next;
		prev = prev->next;
	}
}

void		validate_tokens(t_parser *parser, t_token *tokens)
{
	t_token	*token;
	int		op;
	int		y;

	token = tokens;
	while (token)
	{
		op = 0;
		y = token->point.row;
		while (token && y == token->point.row)
		{
			if (token->type == OP_TYPE || token->type == END_FILE)
				op++;
			token = token->next;
		}
		if (op != 1)
			core_error(parser, ERR_OPS, NULL, NULL);
		if (token)
			y = token->point.row;
	}
}
