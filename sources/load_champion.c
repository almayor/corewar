/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 04:26:26 by fallard           #+#    #+#             */
/*   Updated: 2020/11/08 12:11:38 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check_magic(char *file, int fd)
{
	uint8_t		buf[4];
	uint32_t	magic;

	ft_memset(&buf, 0, 4);
	if (read(fd, buf, 4) != 4)
		put_error(READ_ERROR, file, strerror(errno));
	magic = buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3];
	if (magic != COREWAR_EXEC_MAGIC)
		put_error("Error! File '%s' has bad magic number\n", NULL, file);
}

static void	read_name_and_comment(char *file, int n, int fd)
{
	uint8_t buf[COMMENT_LENGTH + 1];

	ft_memset(&buf, 0, COMMENT_LENGTH + 1);
	if (read(fd, g_vm.champs[n].name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		put_error(READ_ERROR, file, "Unknown error");
	if (read(fd, buf, COMMENT_LENGTH) != COMMENT_LENGTH)
		put_error(READ_ERROR, file, "Unknown error");
	g_vm.champs[n].size = buf[6] << 8 | buf[7];
		//ft_printf("Size: {3}%4u{0}, player: {2}%s{0}\n", g_vm.champs[n].size, file);
	if (g_vm.champs[n].size > CHAMP_MAX_SIZE)
	{
		ft_printf(CHAMP_TOO_LARGE, file, g_vm.champs[n].size);
		put_error("", NULL, "");
	}
	ft_strcpy(g_vm.champs[n].comment, buf + 8);
}

static void	read_bytecode(char *file, int fd, uint32_t pos)
{
	uint8_t		buf[CHAMP_MAX_SIZE];
	uint32_t	bytes;
	int			i;

	i = 0;
	ft_memset(&buf, 0, CHAMP_MAX_SIZE);
	bytes = read(fd, buf, CHAMP_MAX_SIZE); // PROTECT
	while (buf[i] == '\0' && i < bytes)
		i++;
	while (i < bytes)
	{
		g_vm.mem[pos] = buf[i];
		pos++;
		i++;
	}
}

static void	load_champion(int *fd, char *file, int n, uint32_t pos)
{
	n = n - 1;
	if ((*fd = open(file, O_RDONLY)) < 0)
		put_error(OPEN_ERROR, file, strerror(errno));
	check_magic(file, *fd);
	g_vm.champs[n].ichamp = n + 1;
	read_name_and_comment(file, n, *fd);
	read_bytecode(file, *fd, pos);
}

void		load_all_champions(void)
{
	int i;
	int step;
	int pos;

	i = 0;
	step = MEM_SIZE / get_nbr_champions();
	pos = 0;
	while (i < 4)
	{
		if (g_vm.args[i].num > 0)
		{
			load_champion(&g_vm.args[i].fd, g_vm.args[i].fname,
				g_vm.args[i].num, pos);
			pos = pos + step;
		}
		i++;
	}
}
