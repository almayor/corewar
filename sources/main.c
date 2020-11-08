/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:21:39 by fallard           #+#    #+#             */
/*   Updated: 2020/11/08 09:30:31 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	g_vm;

void	print_args()
{
	ft_printf("\n");
	for(int i = 0; i < 4; i++) 
	{
		ft_printf("fd: %d, num: %d, name: %s\n", g_vm.args[i].fd,
			g_vm.args[i].num, g_vm.args[i].fname);
	}
}

void	print_logs() // DEL
{
	int i = 0;
	ft_printf("\n");
	while (i < 4)
	{
		if (g_vm.champs[i].ichamp > 0)
		{
			ft_printf("   name: %s\n", g_vm.champs[i].name);
			ft_printf("    num: %u\n", g_vm.champs[i].ichamp);
			ft_printf("comment: %s\n", g_vm.champs[i].comment);
			ft_printf("   size: %u\n", g_vm.champs[i].size);
			ft_printf("--------------------------------\n");
		}
		i++;
	}
}

int main(int argc, char**argv) 
{
	ft_memset(&g_vm, 0, sizeof(t_vm));
	if (argc > 1)
	{
		read_args(argc, argv);
			//ft_printf("dump: %llu\n", g_vm.dump_ncycles);
	
		load_all_champions();
		//print_args();
		print_logs();
		if (g_vm.dump_flag)
			print_dump();
	}
	/*
	int fd = 0;
	unsigned char buf[10] = {0};
	fd = open("42.cor", O_RDONLY);
	int n = read(fd, buf, 4);
	buf[4] = '\0';
	unsigned int magic_num = buf[0] << 24
				| buf[1] << 16
				| buf[2] << 8
				| buf[3];
	ft_printf("1: %x - %u\n", buf[1], buf[1]);
	ft_printf("2: %x - %u\n", buf[2], buf[2]);
	ft_printf("3: %x - %u\n", buf[3], buf[3]);
	for(int i = 0; i < 4; i++) {
		ft_printf("%x", buf[i]);
	}
	*/

	return (0);
}
