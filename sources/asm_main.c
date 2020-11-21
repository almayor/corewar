/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:22:05 by kysgramo          #+#    #+#             */
/*   Updated: 2020/11/21 18:30:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// void	terminate(char *s)
// {
// 	if (errno == 0)
// 		ft_putendl_fd(s, 2);
// 	else
// 		perror(s);
// 	exit(1);
// }

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

// int		ft_bonus(char *av)
// {
// 	if (!ft_strcmp(av, "-t"))
// 		return (1);
// 	else if (!ft_strcmp(av, "-l"))
// 		return (2);
// 	else
// 		return (-1);
// }

t_flags		parse_asm_flags(int ac, char **av)
{
	int			i;
	t_flags		flags;

	i = 2;
	flags.tokens = 0;
	flags.labels = 0;
	flags.help = 0;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-t") || !ft_strcmp(av[i], "--tokens") ||
		!ft_strcmp(av[i], "-tl") || !ft_strcmp(av[i], "-lt"))
			flags.tokens = 1;
		if (!ft_strcmp(av[i], "-l") || !ft_strcmp(av[i], "--labels") ||
		 !ft_strcmp(av[i], "-tl") || !ft_strcmp(av[i], "-lt"))
			flags.labels = 1;
		if (!ft_strcmp(av[i], "-h") || !ft_strcmp(av[i], "--help"))
			flags.help = 1;
		i++;
	}
	if (flags.help + flags.labels + flags.tokens != i - 2)
		core_error(NULL, NULL, *put_asm_usage, NULL);
	return (flags);
}

int		main(int ac, char **av)
{
	t_flags		flags;

	if (ac >= 2 && ac < 6 && is_filename(av[1], ".s"))
	{
		flags = parse_asm_flags(ac, av);
		assembler(av[1], flags);
	}
	else
		put_asm_usage();
	return (0);
}
