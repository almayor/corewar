/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 06:19:40 by fallard           #+#    #+#             */
/*   Updated: 2020/11/08 09:58:26 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
# include "libft.h"
# include "op.h"
# include "corewar_logs.h"

typedef struct	s_args
{
	char	*fname;
	int		num;
	int		fd;
}				t_args;

typedef struct	s_proc
{
	int32_t			reg[REG_NUMBER];
	int32_t			pc;
	uint8_t			carry;
	uint8_t			ichamp;
	uint8_t			opcode;
	uint8_t			cycles_busy;
	int32_t			cycles_since_live;
	struct s_proc	*next;
}				t_proc;

typedef struct	s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	uint32_t		ichamp;
	char			comment[COMMENT_LENGTH];
	size_t			size;
	uint64_t		curr_nlive;
	uint64_t		prev_nlive;
}				t_champ;

typedef struct	s_vm
{
	uint8_t			mem[MEM_SIZE];
	int				nchamps;
	t_champ			champs[MAX_PLAYERS];
	size_t			nprocs;
	t_proc			*procs;
	uint64_t		curr_nlive;
	uint32_t		last_live_champ;
	int64_t			cycles_to_die;
	int64_t 		cycles_since_change;
	int64_t			cycles_since_die;
	uint64_t		dump_ncycles;
	int				dump_flag;
	t_args			args[4];
}				t_vm;

extern	t_vm	g_vm;

typedef void (*t_instruct)(t_proc *proc);


void	put_error(char *format, char *file, char *error);


void	read_args(int argc, char **argv);
void	validate_n(int argc, char **argv, int *i);
void	load_champion(int *fd, char *file, int n, uint32_t pos);
void	save_player(int num, char *argv, char *snum);
int		close_all_fd();

void	validate_dump(int argc, char **argv, int *i);
void	print_dump();
void	print_logs();
void	load_all_champions();
void	init_numbers();



# endif
