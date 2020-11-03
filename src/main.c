#include "corewar.h"

t_vm	g_vm = {0, {0}, 0, 0, 0, 0, CYCLE_TO_DIE, 0, 0, 0};

static void	init_procs(void)
{
	t_proc	*proc;

	proc = g_vm.procs;
	while (proc)
	{
		proc->opcode = g_vm.mem[proc->pc];
		if (proc->opcode > 0 && proc->opcode <= NUM_INSTRUCT)
			proc->cycles_busy = g_op_tab[proc->opcode].duration;
		else
			proc->opcode = 0;
		proc = proc->next;
	}
}

static void	create_proc(uint32_t ichamp, uint32_t pos)
{
	t_proc	*proc;

	proc = ft_xcalloc(sizeof(t_proc), 1);
	proc->pc = pos;
	proc->reg[0] = ichamp;
	proc->next = g_vm.procs;
	g_vm.procs = proc;
}

int			main(int argc, char **argv)
{
	process_args(argc, argv);
	run();
	if (g_vm.last_live_champ)
		ft_printf(
				PLAYER_WON, g_vm.last_live_champ,
				g_vm.champs[g_vm.last_live_champ].name);
	else
		ft_printf(NO_LIVE);
	terminate(0);
}
