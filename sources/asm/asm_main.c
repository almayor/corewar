/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:22:05 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/16 22:15:13 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int		ft_strstr_n(const char *haystack, const char *needle)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = 0;
	if (needle[j] == '\0')
		return (0);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && needle[j])
				j++;
			if (needle[j] == '\0')
			{
				n++;
				j = 0;
			}
		}
		i++;
	}
	return (n);
}

int		is_filename(char *filename, char *ext)
{
	if (filename && ext && ft_strlen(filename) >= ft_strlen(ext)
			&& ft_strstr(filename, ext) && ft_strstr_n(filename, ext) == 1
			&& !ft_strcmp(ft_strchr(filename, '\0') - ft_strlen(ext), ext))
		return (TRUE);
	return (FALSE);
}

int		main(int ac, char **av)
{
	if (ac == 2 && is_filename(av[1], ".s"))
	{
		assembler(av[1]);
	}
	else
		ft_printf("Usage: ./asm <champion>.s\n");
	return (0);
}
