/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 04:26:26 by fallard           #+#    #+#             */
/*   Updated: 2020/11/09 21:14:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	read_magic(char *file, int fd)
{
	uint8_t		buf[4];
	uint32_t	magic;

	ft_memset(buf, 0, 4);
	if (read(fd, buf, 4) != 4)
		terminate(READ_ERROR, file, strerror(errno));
	magic = buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3];
	if (magic != COREWAR_EXEC_MAGIC)
		terminate(READ_ERROR, "Error! File '%s' has bad magic number\n", file);
}

static void	read_header(const char *file, int n, int fd)
{
	uint8_t		buf[8];

	ft_memset(buf, 0, 8);
	if (read(fd, g_vm.champs[n].name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		terminate(READ_ERROR, file, "couldn't read champion's name");
	if (read(fd, buf, 8) != 8)
		terminate(READ_ERROR, file, "couldn't read champion's size");
	if (read(fd, g_vm.champs[n].comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		terminate(READ_ERROR, file, "couldn't read champion's comment");
	g_vm.champs[n].size =
		buf[0] << 56
		| buf[1] << 48
		| buf[2] << 40
		| buf[3] << 32
		| buf[4] << 24
		| buf[5] << 16
		| buf[6] << 8
		| buf[7];
	//ft_printf("Size: {3}%4u{0}, player: {2}%s{0}\n", g_vm.champs[n].size, file);
	if (g_vm.champs[n].size > CHAMP_MAX_SIZE)
		terminate(
			CHAMP_TOO_LARGE,
			g_vm.champs[n].ichamp, g_vm.champs[n].name, g_vm.champs[n].size
		);
}

static void	read_bytecode(const char *file, int n, int fd, uint32_t pos)
{
	uint8_t		buf[CHAMP_MAX_SIZE];
	uint32_t	bytes;
	int			i;

	ft_memset(buf, 0, CHAMP_MAX_SIZE);
	if ((bytes = read(fd, buf, CHAMP_MAX_SIZE)) != g_vm.champs[n].size)
		terminate(CHAMP_WRONG_SIZE, n, g_vm.champs[n].name);
	i = 0;
	// while (buf[i] == '\0' && i < bytes)
	// 	i++;
	while (i < bytes)
	{
		g_vm.mem[pos] = buf[i];
		pos++;
		i++;
	}
}

static void	load_champion(const char *file, int n, uint32_t pos)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		put_error(OPEN_ERROR, file, strerror(errno));
	g_vm.champs[n].ichamp = n + 1;
	read_magic(file, fd);
	read_name_and_comment(file, n, fd);
	read_bytecode(file, n, fd, pos);
	close(fd);
}

void		load(int argc, char **argv)
{
	t_args	args[4];
	int 	i;
	int 	step;
	int 	pos;

	ft_memset(args, 0, sizeof(args));
	read_args(argc, argv, &args);
	if (!(g_vm.nchamps = get_nbr_champions()))
		terminate("%s\n", NO_PLAYERS);
	step = MEM_SIZE / g_vm.nchamps;
	pos = 0;
	i = 0;
	while (i < 4)
	{
		if (g_vm.args[i].num > 0)
		{
			load_champion(args[i].fname, args[i].num - 1, pos);
			create_proc(args[i].num, args[i].pos);
			pos += step;
		}
		i++;
	}
}
