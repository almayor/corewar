/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:09:59 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/16 22:16:03 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	validate_commands(t_parser *parser)
{
	if (parser->name == NULL)
		terminate(ERR_NO_NAME);
	if (parser->comment == NULL)
		terminate(ERR_NO_COMMENT);
	if (ft_strlen(parser->name) > PROG_NAME_LENGTH)
		terminate(ERR_TOO_LONG_NAME);
	if (ft_strlen(parser->comment) > COMMENT_LENGTH)
		terminate(ERR_TOO_LONG_COMMENT);
}

int			read_row(int fd, char **row)
{
	int size;

	if ((size = get_next_line(fd, row) <= 0))
	{
		if ((*row) == NULL)
			return (-1);
		if (size == -1)
			terminate(ERR_READING);
	}

	return (TRUE);
}

void	trim_from_comments_spaces(t_parser *parser, char *row)
{
	while (row[parser->x_read] == ' ' || row[parser->x_read] == '\t' ||
			row[parser->x_read] == '\n')
		parser->x_read++;
	if (row[parser->x_read] == COMMENT_CHAR ||
			row[parser->x_read] == ALT_COMMENT_CHAR)
		while (row[parser->x_read] && row[parser->x_read] != '\n')
			parser->x_read++;
	if (row[parser->x_read] == '\"')
		parser->x_read++;
}

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
			parse_alpha(parser, *row, parser->x_read, init_token(parser, UNKNOWN));
	}	
	else
	{
		if (*(*row + parser->x_read) == LABEL_CHAR && ++parser->x_read)
			parse_alpha(parser, *row, parser->x_read,
					init_token(parser, IND_LABL_ARG_TYPE));
		else 
			parse_digit(parser, *row, parser->x_read, init_token(parser, IND_ARG_TYPE));;
	}
		
}

/*
** parse_alpha - for operatioins, starting labels, operations and registers 
** parse_digit - for directs, indirects
*/

void		print_labels(t_label *labels)
{
	t_label *label;

	label = labels;
	while (label)
	{
		ft_printf("{red}->%s, %d, %d{eoc}\n", label->content, label->point.row, label->point.token);
		label = label->next;

	}
}

void		print_tokens(t_token *tokens)
{
	int y;
	t_token *token;

	token = tokens;
	y = token->point.row;
	while (token)
	{
		if (y != token->point.row)
			ft_printf("\n");
		if (token->type == 1 || token->type == 6 || token->type ==8)
			ft_printf("{red}->%s, %d, %d, %d {eoc}\n", token->content, token->point.row, token->point.token, token->type);
		else
			ft_printf("{green}->%s, %d, %d, %d {eoc}\n", token->content, token->point.row, token->point.token, token->type);
		y = token->point.row;
		token = token->next;

	}
}

void		improve_coords(t_token *tokens)
{
	int y;
	t_token *token;

	token = tokens;
	y = token->point.row;
	while (token)
	{
		if (token->point.token == 0)
			y++;
		if (token->point.row != y)
			token->point.row = y;
		token = token->next;
	}
}

int			hard_coord(t_parser *parser, t_token **token, int tok_num)
{
	t_token *check;
	int		c;

	c = 0;
	check = *token;
	while (check->type == 1)
	{
		check = check->next;
		c++;
	}
	while (1)
	{
		tok_num++;
		(*token)->point.token = tok_num;
		(*token)->point.row = check->next->point.row;
		add_label(&parser->labels,
		init_label((*token)->content, (*token)->point.row, c));
		if ((*token)->next->type == 1)
			(*token) = (*token)->next;
		else
			break ;
	}
	return (tok_num);
}

void		coords_and_labels(t_parser *parser, t_token *tokens, int tok_num)
{
	int y;
	t_token *token;

	token = tokens;
	y = token->point.row;
	while (token)
	{
		if (y != token->point.row)
		{
			tok_num = -1;
			if (token->type == 1 && token->next->point.row != y)
				tok_num = hard_coord(parser, &token, tok_num);
			else
			{
				tok_num++;
				token->point.token = tok_num;
			}	
		}
		else
		{
			tok_num++;
			token->point.token = tok_num;
			if (token->type == 1)
				add_label(&parser->labels,
				init_label(token->content, token->point.row, token->point.token + 1));
		}
		y = token->point.row;
		token = token->next;
	}
}

void		parsing(t_parser *parser)
{
	char	*row;

	while (++parser->point.row && read_row(parser->fd_s, &row) > 0)
	{
		//ft_printf("%d\n", ft_strlen(row));
		parser->x_read = 0;
		//ft_printf("row: %s\n", row);
		while (row[parser->x_read])
		{
			trim_from_comments_spaces(parser, row);
			if (row[parser->x_read])
				parse_token(parser, &row);
		}
		ft_strdel(&row);

	}
	add_token(&parser->tokens, init_token(parser, END_FILE));
	validate_commands(parser);
	coords_and_labels(parser, parser->tokens, -1);
	//improve_coords(parser->tokens);
	print_tokens(parser->tokens);
	print_labels(parser->labels);
	ft_printf("%s\n", parser->name);
	ft_printf("%s\n", parser->comment);
}

/* 
 ** ++parser->point->x - read by symbol
 ** && !(parser->point->y == 0) - ignore empty rows
 ** && read_x(parser->fd_s, &row) - row is not NULL
 */
