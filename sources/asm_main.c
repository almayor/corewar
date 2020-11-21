/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:22:05 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/17 20:44:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

int		ft_bonus(char *av)
{
	if (!ft_strcmp(av, "-t"))
		return (1);
	else if (!ft_strcmp(av, "-l"))
		return (2);
	else
		return (-1);
}

int		main(int ac, char **av)
{
	int bonus1;
	int bonus2;

	bonus1 = 0;
	bonus2 = 0;
	if (ac >= 2 && ac < 5 && is_filename(av[1], ".s"))
	{
		if (av[2])
			bonus1 = ft_bonus(av[2]);
		if (av[3])
			bonus2 = ft_bonus(av[3]);
		assembler(av[1], bonus1, bonus2);
	}
	else
		ft_printf("Usage: ./asm <champion>.s\n");
	return (0);
}
