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

void    parse_alpha(t_parser *parser, char *row, unsigned y_start,
t_token *token)
{
	token->point->y = y_start;
	if (row[parser->point->y] == '-')
		parser->point->y++;
	}

// move by one symbol until LABEK_CHAR
// check that all symbols are from LABEL_CHARS
// detect token type - direct or indirect
// write in token?