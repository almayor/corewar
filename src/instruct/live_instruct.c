#include "corewar.h"

void	live_instruct(t_proc *proc)
{
	uint32_t	ichamp;

	ichamp = g_vm.mem[(proc + 1) % MEM_SIZE];
	if (ichamp < MAX_PLAYERS)
	{
		proc->cycles_since_live = 0;
		g_vm.champs[ichamp].curr_nlive++;
		g_vm.curr_nlive++;
		g_vm.last_live_champ = ichamp;
	}
}
