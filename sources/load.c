/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:24:15 by fallard           #+#    #+#             */
/*   Updated: 2020/11/05 08:12:47 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"
#include <fcntl.h>

static int	check_magic(int fd)
{
	static char	magic_arr[4];
	uint32_t	magic_num;	

	if (read(fd, magic_arr, 4) != 4)
		return (1);
	magic_num = magic_arr[0] << 24
				| magic_arr[1] << 16
				| magic_arr[2] << 8
				| magic_arr[3];
	return (magic_num == COREWAR_EXEC_MAGIC);
}

static int	load_bytecode(int fd, uint32_t pos)
{
	static char	bytecode[CHAMP_MAX_SIZE];
	ssize_t		nbytes;
	size_t		i;

	ft_bzero(bytecode, CHAMP_MAX_SIZE);
	if ((nbytes = read(fd, bytecode, CHAMP_MAX_SIZE)) <= 0)
		return (1);
	i = 0;
	while (i < nbytes)
		mem_write_8bit(pos++, bytecode[i++]);
	return (0);
}

static int	check_champ_size(int fd)
{
	static char	test[1];

	return (read(fd, test, 1) != 0);
}

void 		load(const char *file, int ichamp, uint32_t	pos)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_printf(FILE_NOT_ACCESS, file);
	else if (check_magic(fd))
		ft_printf(FILE_NOT_EXE, file);
	else if (read(fd, g_vm.champs[ichamp].name, PROG_NAME_LENGTH)
			!= PROG_NAME_LENGTH ||
			read(fd, g_vm.champs[ichamp].comment, COMMENT_LENGTH)
			!= COMMENT_LENGTH)
		ft_printf(FILE_MANGLED, file);
	else if (load_bytecode(fd, pos))
		ft_printf(FILE_MANGLED, file);
	else if (check_champ_size(fd))
		ft_printf(CHAMP_TOO_LARGE, ichamp, g_vm.champs[ichamp].name);
	else
		return ;
	terminate(1);
}
