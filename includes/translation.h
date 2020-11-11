/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:51:46 by user              #+#    #+#             */
/*   Updated: 2020/11/11 22:18:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TRANSLATION_H_
# define _TRANSLATION_H_


# include <stdlib.h>
# include <fcntl.h>

# include "libft.h"
# include "asm_struct_new.h"
# include "op.h"

/*
**	Translation to byte code
*/

void		translation(t_frame *stor);


/*
**	Utils to handle error cases and memory management
*/

void		core_error(t_frame *stor, char *message);
void		core_free(t_frame *stor);

#endif