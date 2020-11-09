/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:42:53 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/09 18:43:38 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void    parse_symbols(t_parser *parser, char *row, unsigned y_start,
t_token *token)
{
	token->y = y_start;
	if (row[parser->y_read] == '-')
		parser->y_read++;
	
}