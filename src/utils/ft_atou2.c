#include "utils.h"

int	ft_atou2(const char *str, uint64_t *res)
{
	int	digit;

	while (ft_isspace(*str))
		str++;
	*res = 0;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (*res > (ULONG_MAX - digit) / 10)
			return (1);
		*res = (*res * 10) + digit;
		str++;
	}
	return (0);
}
