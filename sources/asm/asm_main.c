/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:22:05 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/08 19:22:08 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_help(void)
{
	ft_printf("Usage: ./asm <champion>.s\n");
}

int		is_filename(char *filename, char *ext)
{
	if (filename && ext && ft_strlen(filename) >= ft_strlen(ext)
	&& ft_strstr(filename, ext))
	{
		ft_printf("%s\n", ft_strchr(filename, '.') );
		return (TRUE);
	}
	return (FALSE);
}

int		main(int ac, char **av)
{
    if (ac == 2 && is_filename(av[1], ".s"))
    {
    	ft_printf(" \n");
    }
	else
		print_help();

    return (1);
}
