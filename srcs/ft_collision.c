#include <math.h>
#include <stdio.h>
#include "rtv1.h"

double	*matrice_multi_double(double *fst, double *scd)
{
	double	*ret;
	double	*tmp;
	int	x;
	int	y;
	int	a;

	y = -1;
	if (fst[0] != scd[1])
		return (NULL);
	ret = (double*)ft_memalloc((int)(sizeof(double) * ((fst[1] * scd[0] + 2))));
	ret[0] = scd[0];
	ret[1] = fst[1];
	tmp = &ret[2];
	while (++y < ret[1] && (x = -1))
		while (++x < ret[0] && (a = -1))
			while (++a < fst[0])
				ret[(int)(2 + x + y * scd[0])] +=
					fst[(int)(a + y * fst[0] + 2)] * scd[(int)(a * scd[0] + x + 2)];
	return (ret);
}

double	*rotate(double *vector, t_rotation deg)
{
	double			*ret;
	double			*tmp;
	double			*rot;

	rot = (double[11]){3, 3, 1, 0, 0, 0, cos(deg.rot_x), -sin(deg.rot_x), 0,
		sin(deg.rot_x), cos(deg.rot_x)};
	ret = matrice_multi_double(rot, vector);
	printf("premier transformation\n%lf %lf\n%lf %lf %lf\n", ret[0], ret[1], ret[2], ret[3], ret[4]);
	tmp = ret;
	rot = (double[11]){3, 3, cos(deg.rot_y), 0, sin(deg.rot_y), 0, 1, 0,
		-sin(deg.rot_y), 0, cos(deg.rot_y)};
	ret = matrice_multi_double(rot, tmp);
	printf("\ndeuxieme transformation\n%lf %lf\n%lf %lf %lf\n", ret[0], ret[1], ret[2], ret[3], ret[4]);
	ft_memdel((void*)&tmp);
	tmp = ret;
	rot = (double[11]){3, 3, cos(deg.rot_z), -sin(deg.rot_z), 0, sin(deg.rot_z),
		cos(deg.rot_z), 0, 0, 0, 1};
	ret = matrice_multi_double(rot, tmp);
	printf("\nfinal:\n%lf %lf\n%lf %lf %lf\n", ret[0], ret[1], ret[2], ret[3], ret[4]);
	ft_memdel((void*)&tmp);
	return (ret);
}

int		ft_col_sphere(t_object obj, t_coord pos)
{
	if (obj.height <= sqrt(pow((obj.pos.x - pos.x), 2) +
				pow((obj.pos.y - pos.y), 2) + pow((obj.pos.z - pos.z), 2)))
		return (1);
	return (0);
}

int		ft_col_plan(t_object obj, t_coord point)
{
	double		*corner_a;
	double		*corner_b;

	t_rotation	rot;

	corner_a = (double[5]){1, 3, obj.width / 2, obj.height / 2, obj.depth / 2};
	corner_a = rotate(corner_a, obj.rotation);
	corner_a = (double[5]){1, 3, corner_a[2] + obj.pos.x, corner_a[3] +
		obj.pos.y, corner_a[4] + obj.pos.z};
	corner_b = (double[5]){1, 3, -obj.width / 2, obj.height / 2, obj.depth / 2};
	corner_b = rotate(corner_b, obj.rotation);
	corner_b = (double[5]){1, 3, corner_b[2] + obj.pos.x, corner_b[3] +
		obj.pos.y, corner_b[4] + obj.pos.z};

	return (0);
}

int		ft_col_cone(t_object obj, t_coord pos)
{
	return (0);
}

int		ft_col_cylinder(t_object obj, t_coord pos)
{
	return (0);
}

int main()
{
	return (0);
}
