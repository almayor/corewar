/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:49:00 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/21 21:07:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "operations.h"

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
	int	i;

	i = 0;
	while (i <= AFF)
	{
		if (!ft_strcmp(g_op_tmpl[i].name, token->content))
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
			if (i > 0 && i < 17)
			{
				token->type = REG_ARG_TYPE;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}
