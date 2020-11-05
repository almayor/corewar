#include "corewar.h"

static void	free_procs(void)
{
	t_proc	*proc;

	proc = g_vm.procs;
	while (proc)
	{
		free(proc);
		proc = proc->next;
	}
}

void		cleanup(void)
{
	free_procs();
}

void		terminate(const char *format, ...)
{
	va_list	ap;

	va_start(ap);
	ft_vdprintf(STDERR_FILENO, format, ap);
	va_end(ap);
	cleanup();
	exit(ERROR_RETCODE);
}
