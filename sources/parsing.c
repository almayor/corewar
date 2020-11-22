/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:09:59 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/22 21:29:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		add_token(t_token **tokens, t_token *token)
{
	t_token *curr;

	if (tokens && *tokens)
	{
		curr = *tokens;
		while (curr->next)
			curr = curr->next;
		curr->next = token;
	}
	else
		*tokens = token;
}

void		parse_token2(t_parser *parser, char **row)
{
	if (*(*row + parser->x_read) == LABEL_CHAR && ++parser->x_read)
		parse_alpha(parser, *row, parser->x_read,
				init_token(parser, IND_LABL_ARG_TYPE));
	else if (*(*row + parser->x_read) == '-')
		parse_digit(parser, *row, parser->x_read,
			init_token(parser, IND_ARG_TYPE));
	else
		lexical_error(parser, NULL, row);
}

void		parse_token(t_parser *parser, char **row)
{
	if (*(*row + parser->x_read) == SEPARATOR_CHAR)
		parser->x_read++;
	else if (*(*row + parser->x_read) == '.' && ++parser->x_read)
		parse_command(parser, row, parser->x_read);
	else if (*(*row + parser->x_read) == DIRECT_CHAR && ++parser->x_read)
	{
		if (*(*row + parser->x_read) == LABEL_CHAR && ++parser->x_read)
			parse_alpha(parser, *row, parser->x_read,
					init_token(parser, DIR_LABL_ARG_TYPE));
		else
			parse_digit(parser, *row, parser->x_read,
			init_token(parser, DIR_ARG_TYPE));
	}
	else if (ft_strchr(LABEL_CHARS, *(*row + parser->x_read)))
	{
		if (ft_isalpha(*(*row + parser->x_read)))
			parse_alpha(parser, *row, parser->x_read,
			init_token(parser, UNKNOWN));
		else
			parse_digit(parser, *row, parser->x_read,
			init_token(parser, IND_ARG_TYPE));
	}
	else
		parse_token2(parser, row);
}

/*
** parse_alpha - for operatioins, starting labels, operations and registers
** parse_digit - for directs, indirects
*/

void		token_len(t_parser *parser, t_token **tokens)
{
	t_token	*curr;
	int		len;

	len = 0;
	if (tokens && *tokens)
	{
		curr = *tokens;
		while (curr->next)
		{
			curr = curr->next;
			len++;
		}
		parser->tok_len = len;
	}
	else
		parser->tok_len = 0;
}

void		parsing(t_parser *parser, int tok_len)
{
	char	*row;

	row = NULL;
	while (++parser->y_read && read_row(parser->fd_s, &row, parser) > 0)
	{
		parser->x_read = 0;
		while (row[parser->x_read])
		{
			trim_from_comments_spaces(parser, row);
			if (row[parser->x_read])
				parse_token(parser, &row);
		}
		token_len(parser, &parser->tokens);
		if (tok_len != parser->tok_len)
		{
			tok_len = parser->tok_len;
			parser->point.row++;
		}
		ft_strdel(&row);
	}
	if (tok_len == 0)
		core_error(parser, ERR_NO_CODE, NULL, NULL);
	add_token(&parser->tokens, init_token(parser, END_FILE));
	validate_commands(parser);
	coords_and_labels(parser, parser->tokens, -1);
}

/*
** print_tokens(parser->tokens);
** print_labels(parser->labels);
** ++parser->point->x - read by symbol
** && !(parser->point->y == 0) - ignore empty rows
** && read_x(parser->fd_s, &row) - row is not NULL
*/
