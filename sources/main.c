/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:14:21 by user              #+#    #+#             */
/*   Updated: 2020/11/12 02:38:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_struct.h"
#include "translation.h"

int		main()
{
	t_parser	*stor;

	stor = ft_calloc(1, sizeof(t_parser));
	
	stor->file_name = ft_strdup("myfile.cor");
	stor->name = ft_strdup("Hero");
	stor->comment = ft_strdup("initial comment");
	stor->code_total_size = 10;

	translation(stor);
	core_free(stor);
}