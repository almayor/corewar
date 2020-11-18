/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:42:53 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/18 18:47:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		lexical_error(t_parser *parser)
{
	ft_printf("Lexical error at row %d, symbol %d\n",
	parser->y_read, parser->x_read);
	core_error(parser, NULL);
}

void		add_label(t_label **labels, t_label *label)
{
	t_label *curr;

	if (labels && *labels)
	{
		curr = *labels;
		while (curr->next)
			curr = curr->next;
		curr->next = label;
	}
	else
		*labels = label;
}

char		*get_token_content(t_parser *parser, char *row, int start)
{
	char	*content;

	content = NULL;
	if (!(content = ft_strsub(row, start, parser->x_read - start)))
		core_error(parser, ERR_STR_INIT);
	return (content);
}

void		parse_alpha(t_parser *parser, char *row, int start,
		t_token *token)
{
	while (row[parser->x_read] && ft_strchr(LABEL_CHARS, row[parser->x_read]))
		parser->x_read++;
	token->content = get_token_content(parser, row, start);
	if (parser->x_read - start && (row[parser->x_read] == LABEL_CHAR ||
	row[start - 1] == LABEL_CHAR))
	{
		add_token(&parser->tokens, token);
		if (token->type == UNKNOWN)
		{
			token->type = LABEL_TYPE;
			parser->x_read++;
		}
	}
	else if (parser->x_read - start && is_delimiter(row[parser->x_read]) &&
			(is_operation(token) || is_register(token)))
		add_token(&parser->tokens, token);
	else
		lexical_error(parser);
}

/*
** move by one symbol until LABEL_CHAR
** check that all symbols are from LABEL_CHARS
** detect token type - label, operation or register?
** write in token?
*/

void		parse_digit(t_parser *parser, char *row, int start,
t_token *token)
{
	if (row[parser->x_read] == '-')
		parser->x_read++;
	while (ft_isdigit(row[parser->x_read]))
		parser->x_read++;
	token->content = get_token_content(parser, row, start);
	if (parser->x_read - start)
		add_token(&parser->tokens, token);
	else
		lexical_error(parser);
}
