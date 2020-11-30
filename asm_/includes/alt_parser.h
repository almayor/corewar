/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:17:39 by user              #+#    #+#             */
/*   Updated: 2020/11/30 21:03:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALT_PARSER_H
# define ALT_PARSER_H

# include "asm_struct.h"
# include "libft.h"

# include <stdio.h>

# define ALT_COMMENT	';'
# define NAME_STEP		ft_strlen(NAME_CMD_STRING)
# define COMM_STEP		ft_strlen(COMMENT_CMD_STRING)

# define READ_ERR			"NEW Error: failed to read file"
# define UNX_COMM_ERR		"NEW Error: unexpected command"


void		alt_parsing(t_parser *stor);

#endif