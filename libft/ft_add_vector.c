#include "libft.h"

void	ft_add_vector(double *fst, char sign, double *scd, double *res)
{
	if (sign == '+')
	{
		res[0] = fst[0] + scd[0];
		res[1] = fst[1] + scd[1];
		res[2] = fst[2] + scd[2];
	}
	else if (sign == '-')
	{
		res[0] = fst[0] - scd[0];
		res[1] = fst[1] - scd[1];
		res[2] = fst[2] - scd[2];
	}
}
