/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:42:53 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/16 22:16:17 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		lexical_error(t_parser *parser)
{
	ft_printf("Lexical error at row %d, symbol %d\n",
	parser->point.row, parser->x_read);
	exit(1);
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

char	*get_token_content(t_parser *parser, char *row, int start)
{
	char	*content;

	if (!(content = ft_strsub(row, start, parser->x_read - start)))
		terminate(ERR_STR_INIT);
	return (content);
}

int		is_delimiter(int c)
{
	return (c == '\0'
			|| c == '\t'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == ' '
			|| c == '\"'
			|| c == DIRECT_CHAR
			|| c == SEPARATOR_CHAR
			|| c == COMMENT_CHAR
			|| c == ALT_COMMENT_CHAR);
}

int		is_operation(t_token *token)
{
	int	 	i;

	i = 0;
	while (i <= AFF)
	{
		if (!ft_strcmp(op_tmpl[i].name, token->content))
		{
			token->type = OP_TYPE;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int		is_register(t_token *token)
{
	int i;

	i = ft_strlen(token->content);
	if (token->content[0] == 'r' && (i == 2 || i == 3))
	{
		i = 1;
		while (ft_isdigit(token->content[i]))
			i++;
		if (!token->content[i])
		{
			i = ft_atoi(&token->content[1]);
			if (i > 0)
			{
				token->type = REG_ARG_TYPE;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

void	parse_alpha(t_parser *parser, char *row, int start,
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

void	parse_digit(t_parser *parser, char *row, int start,
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

