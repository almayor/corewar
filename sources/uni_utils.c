/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:51:20 by user              #+#    #+#             */
/*   Updated: 2020/11/11 22:12:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm_struct_new.h"
#include "../includes/translation.h"


void		core_error(t_frame *stor, char *message)
{
	if (stor)
		core_free(stor);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void		core_free(t_frame *stor)
{
	if (!stor)
		return ;
	// function to clean all data stored in frame
}