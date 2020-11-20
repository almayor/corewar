/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:44:40 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/21 02:04:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		print_labels(t_label *labels)
{
	t_label *label;

	label = labels;
	while (label)
	{
		ft_printf("{red}->%s, %d, %d{eoc}\n", label->content,
		label->point.row, label->point.token);
		label = label->next;
	}
}

void		print_tokens(t_token *tokens)
{
	int		y;
	t_token	*token;

	token = tokens;
	y = token->point.row;
	while (token)
	{
		if (y != token->point.row)
			ft_printf("\n");
		if (token->type == LABEL_TYPE || token->type == DIR_LABL_ARG_TYPE
		|| token->type == IND_LABL_ARG_TYPE)
			ft_printf("{red}->%s, %d, %d, %d {eoc}\n", token->content,
			token->point.row, token->point.token, token->type);
		else
			ft_printf("{green}->%s, %d, %d, %d {eoc}\n", token->content,
			token->point.row, token->point.token, token->type);
		y = token->point.row;
		token = token->next;
	}
}

int			hard_coord(t_parser *parser, t_token **token, int tok_num, int c)
{
	t_token	*check;

	check = *token;
	while (check->type == LABEL_TYPE)
	{
		check = check->next;
		c++;
	}
	while (1)
	{
		tok_num++;
		(*token)->point.token = tok_num;
		if (check->next != NULL)
			(*token)->point.row = check->next->point.row;
		else
		{
			if ((*token)->point.row == 1)
				core_error(parser, ERR_EMPTY_LABEL, NULL, NULL);
			else
				(*token)->type = UNKNOWN;
			break ;
		}
		add_label(&parser->labels,
		init_label((*token)->content, (*token)->point.row, c, parser));
		if ((*token)->next->type == LABEL_TYPE)
			(*token) = (*token)->next;
		else
			break ;
	}
	return (tok_num);
}

int			tok_num_padding(int tok_num, t_token *token)
{
	tok_num++;
	token->point.token = tok_num;
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
		if (token->type == LABEL_TYPE && token->type != y)
			tok_num = hard_coord(parser, &token, -1, 0);
		else if (y != token->point.row)
			tok_num = tok_num_padding(-1, token);
		else
		{
			tok_num = tok_num_padding(tok_num, token);
			if (token->type == LABEL_TYPE)
				add_label(&parser->labels,
				init_label(token->content, token->point.row,
				token->point.token + 1, parser));
		}
		y = token->point.row;
		token = token->next;
	}
}
