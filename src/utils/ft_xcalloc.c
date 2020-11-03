#include "utils.h"

/*
** Replicates behaviour of `calloc` from `libc`, but fails on
** memory allocation errors.
*/

void	*ft_xcalloc(size_t count, size_t size)
{
	void	*mem;

	mem = ft_calloc(count, size);
	if (!mem && !size)
		terminate(ERR_NO_MEMORY);
	return (mem);
}
