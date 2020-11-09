/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:09:59 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/09 14:10:01 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			read_x(int fd, char **row)
{
	int size;

	if ((size = get_next_line(fd, row) > 0))
	{
		//row[size] = '\0';
	}
	if ((*row) == NULL)
		return (-1);
	if (size == -1)
		terminate(ERR_READING);
	return (TRUE);
}

void	trim_from_comments_spaces(t_parser *parser, char *row)
{
	while (row[parser->y_read] == ' ' || row[parser->y_read] == '\t' ||
	row[parser->y_read] == '\n')
		parser->y_read++;
	if (row[parser->y_read] == COMMENT_CHAR ||
	row[parser->y_read] == ALT_COMMENT_CHAR)
		while (row[parser->y_read] && row[parser->y_read] != '\n')
			parser->y_read++;
}

void		add_token(t_token **tokens, t_token *token)
{
	t_token *curr;

	if (tokens && *tokens)
	{
		curr = *tokens;
		while (curr->next)
			curr = curr->next;
		if (curr->type == NEW_LINE && token->type == NEW_LINE)
			ft_memdel((void **)token);
		else
			curr->next = token;
	}
	else
	{
		if (token->type == NEW_LINE)
			ft_memdel((void **)token);
		else
			*tokens = token;
	}
}

void		parse_token(t_parser *parser, char **row)
{
	if (*row[parser->y_read] == SEPARATOR_CHAR && ++parser->y_read)
		add_token(&parser->tokens, init_token(parser, SEPARATOR_CHAR));
	else if (*row[parser->y_read] == '\n' && ++parser->y_read)
		add_token(&parser->tokens, init_token(parser, NEW_LINE));
	else if (row[parser->y_read] == '.' && ++parser->y_read)
		parse_symbols(parser, *row, parser->y_read++,
		init_token(parser, COMMAND));
	/*else if (row[parser->y_read] == DIRECT_CHAR && ++parser->y_read)
		//add_token(&parser->tokens, init_token(parser, NEW_LINE));
	else if (row[parser->y_read] == '\"' && ++parser->y_read)
		//add_token(&parser->tokens, init_token(parser, STRING));
	//else if (row[parser->y_read] == LABEL_CHAR && ++parser->y_read)
	//	add_token(&parser->tokens, init_token(parser, ));
	else
		//add_token(&parser->tokens, init_token(parser, INDIRECT_LABEL));*/
}

void		parsing(t_parser *parser, int fd)
{
	char	*row;

	while (++parser->y_read && !(parser->y_read == 0) &&
	read_x(fd, &row) > 0)
	{
		while (row[parser->x_read])
		{
			trim_from_comments_spaces(parser, row);
			if (row[parser->x_read])
				parse_token(parser, &row);
		}
		ft_strdel(&row);

	}
}