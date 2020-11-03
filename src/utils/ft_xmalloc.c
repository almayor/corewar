#include "utils.h"

/*
** Replicates behaviour of `malloc` from `libc`, but fails on
** memory allocation errors.
*/

void	*ft_xmalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem && !size)
		terminate(ERR_NO_MEMORY);
	return (mem);
}
