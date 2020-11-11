/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:51:46 by user              #+#    #+#             */
/*   Updated: 2020/11/11 23:02:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TRANSLATION_H_
# define _TRANSLATION_H_


# include <stdlib.h>
# include <fcntl.h>

# include "libft.h"
# include "asm_struct.h"
# include "op.h"

/*
**	Translation to byte code
*/

void		translation(t_parser *stor);


/*
**	Utils to handle error cases and memory management
*/

void		core_error(t_parser *stor, char *message);
void		core_free(t_parser *stor);

#endif