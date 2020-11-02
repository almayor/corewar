#ifndef COREWAR_H

# define COREWAR_H

# include "stdint.h"
# include "utils.h"
# include <limits.h>

typedef struct	s_proc
{
	int32_t			reg[REG_NUMBER];
	int32_t			pc;
	uint8_t			carry;
	uint8_t			ichamp;
	uint16_t		cycles_busy;
	uint32_t		cycles_since_live;
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
	t_champ			champs[MAX_PLAYERS];
	size_t			nprocs;
	t_proc			*procs;
	uint64_t		curr_nlive;
	uint64_t		cycles_to_die;
	uint64_t 		cycles_since_change;
	uint64_t		cycles_since_die;
}				t_vm;

extern	t_vm	g_vm;

# define	PLAYER_ALIVE	"a process shows that player %hhu (%s) is alive"
# define	PLAYER_WON		"player %hhu (%s) won"

# define	FILE_NOT_EXE	"%s is not a corewar executable"
# define	PROG_NUM_USED	"player number %hhu already in use"
# define	FILE_NOT_ACCESS	"file %s not accessible"
# define	MALLOC_ERROR	"malloc error"
# define	CHAMP_TOO_LARGE	"champion %hhu (%s) exceeds maximum size"
# define	INVALID_MACRO	"macro %s values other than %i are not supported"

typedef void (*instruct)(t_proc *proc);

# endif
