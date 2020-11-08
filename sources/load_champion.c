/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 04:26:26 by fallard           #+#    #+#             */
/*   Updated: 2020/11/08 10:06:44 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int is_contain(int n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_vm.args[i].num == n)
			return (1);
		i++;
	}
	return (0);
}

void	init_numbers()
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		if (g_vm.args[i].num < 0)
		{
			while(j < 4)
			{
				if (!is_contain(j + 1))
					break ;
				j++;
			}
			g_vm.args[i].num = j + 1;
		}
		i++;
	}
}

int	close_all_fd()
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_vm.args[i].fd > 0)
			close(g_vm.args[i].fd);
		i++;
	}
	return (1);
}

int get_nbr_champions()
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(i < 4)
	{
		if (g_vm.args[i].num > 0)
			count++;
		i++;
	}
	if (!count)
		put_error("%s\n", NULL, NO_PLAYERS);
	return (count);
}

void	check_magic(char *file, int fd)
{
	uint8_t		buf[4];
	uint32_t	magic;	

	if (read(fd, buf, 4) != 4)
		put_error(READ_ERROR, file, strerror(errno));
	magic = buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3];
	if (magic != COREWAR_EXEC_MAGIC)
		put_error("Error! File '%s' has bad magic number\n", NULL, file);
}

void	read_name_and_comment(char *file, int n, int fd)
{
	uint8_t buf[COMMENT_LENGTH + 1];
	
	ft_memset(&buf, 0, COMMENT_LENGTH + 1);
	read(fd, g_vm.champs[n].name, PROG_NAME_LENGTH); // PROTECT
	read(fd, buf, COMMENT_LENGTH); // PROTECT
	g_vm.champs[n].size = buf[6] << 8 | buf[7];
		//ft_printf("Size: {3}%4u{0}, player: {2}%s{0}\n", g_vm.champs[n].size, file);
	// if (size > CHAMP_MAX_SIZE)
	// {
	// 	ft_printf(CHAMP_TOO_LARGE, file, size);
	// 	put_error("", NULL, "");
	// }
	ft_strcpy(g_vm.champs[n].comment, buf + 8);
}

void	read_bytecode(char *file, int fd, uint32_t pos)
{
	uint8_t buf[CHAMP_MAX_SIZE];
	uint32_t bytes;
	int i;

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
	return ;
}

void	load_champion(int *fd, char *file, int n, uint32_t pos)
{
	n = n - 1;
	if ((*fd = open(file, O_RDONLY)) < 0)
		put_error(OPEN_ERROR, file, strerror(errno));
	check_magic(file, *fd);
	g_vm.champs[n].ichamp = n + 1;
	read_name_and_comment(file, n, *fd);
	read_bytecode(file, *fd, pos);
}

void	load_all_champions()
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
				//ft_printf("pos: %d\n", pos);	// DEL
			load_champion(&g_vm.args[i].fd, g_vm.args[i].fname,
				g_vm.args[i].num, pos);
			pos = pos + step;
		}
		i++;
	}
}
