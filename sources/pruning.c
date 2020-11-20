/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:21:04 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/20 20:21:07 by kysgramo         ###   ########.fr       */
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
			while (token && (token->type != OP_TYPE && token->type != LABEL_TYPE))
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
        if (prev->next && prev->type == LABEL_TYPE && prev->next->type != OP_TYPE)
			core_error(parser, ERR_LABEL_OP);
		if (curr->type == UNKNOWN)
		{
			while (curr->next && curr->type == UNKNOWN)
			{
				tmp = curr;
				curr = curr->next;
				//ft_printf("*%s\n", tmp->content);
				free(tmp->content);
				tmp->content = NULL;
				free(tmp);
				tmp = NULL;
				prev->next = curr;
			}
		}
		curr = curr->next;
		prev = prev->next;
	}
}

