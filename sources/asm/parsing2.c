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
		if (!ft_strcmp(op_tmpl->name, token->content))
		{
			token->type = OP_TYPE;
			return (TRUE);
		}
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
	start = parser->x_read;
	while (row[parser->x_read] && ft_strchr(LABEL_CHARS, row[parser->x_read]))
		parser->x_read++;
	token->content = get_token_content(parser, row, start);
	if (parser->x_read - start && row[parser->x_read] == LABEL_CHAR)
	{
		token->type = LABEL_TYPE;
		add_token(&parser->tokens, token);
		add_label(&parser->labels,
				init_label(get_token_content(parser, row, start), parser->point.row));
		parser->x_read++;
		ft_printf("->%s\n", token->content);
	} 
	else if (parser->x_read - start && is_delimiter(row[parser->x_read]) &&
			(is_operation(token) || is_register(token)))
	{
		add_token(&parser->tokens, token);
		ft_printf("->%s", token->content);
	}
	//else
	//	lexical_error();
}
// move by one symbol until LABEL_CHAR
// check that all symbols are from LABEL_CHARS
// detect token type - direct or indirect
// write in token?

/*
   void    parse_num(t_parser *parser, char *row, int start,
   t_token *token)
   {
   token->point->row = start;
   if (row[parser->x_read] == '-')
   parser->x_read++;
   }
   */
