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

	rot = (double[11]){3, 3, 1, 0, 0, 0, cos(deg.rot_x), -sin(deg.rot_x),
		0, sin(deg.rot_x), cos(deg.rot_x)};
	ret = matrice_multi_double(rot, vector);
	tmp = ret;
	rot = (double[11]){3, 3, cos(deg.rot_y), 0, sin(deg.rot_y), 0, 1, 0,
		-sin(deg.rot_y), 0, cos(deg.rot_y)};
	ret = matrice_multi_double(rot, tmp);
	ft_memdel((void*)&tmp);
	tmp = ret;
	rot = (double[11]){3, 3, cos(deg.rot_z), -sin(deg.rot_z), 0, sin(deg.rot_z),
		cos(deg.rot_z), 0, 0, 0, 1};
	ret = matrice_multi_double(rot, tmp);
	ft_memdel((void*)&tmp);
	return (ret);
}

int		ft_col_sphere(t_object obj, t_coord point)
{
	if (sqrt(pow(obj.pos.x - point.x, 2) + pow(obj.pos.y - point.y, 2) + pow(obj.pos.z - point.z, 2)) <= obj.size.height)
		return (1);
	return (0);
}

int		ft_col_plan(t_object obj, t_coord point)
{
	double		*corner_a;
	double		*corner_b;
	double		const;
	t_rotation	rot;

	corner_a = (double[5]){1, 3, obj.size.width / 2, obj.size.height / 2, obj.size.depth / 2};
	corner_a = rotate(corner_a, obj.rotation);
	corner_b = (double[5]){1, 3, -obj.size.width / 2, obj.size.height / 2, obj.size.depth / 2};
	corner_b = rotate(corner_b, obj.rotation);
	corner_b = (double[5]){1, 3, corner_b[2] + obj.pos.x, corner_b[3] +
		obj.pos.y, corner_b[4] + obj.pos.z};
	const = corner_a[2] * corner_b[2] + corner_a[3] * corner_b[3] +
		corner_a[4] * corner_b[4];
	if (const == corner_a[2] * point.x + corner_a[3] * point.y +
			corner_a[4] * point.z)
		return (1);
	return (0);
}

int		ft_col_cone(t_object obj, t_coord point)
{
	double	*center;
	double	*top;
	double	coef_cone;
	double	coef_pt;

	center = (double[5]){1, 3, -obj.size.height / 2, 0};
	top = (double[5]){1, 3, 0, obj.size.height / 2, 0};
	center = rotate(center, obj.rotation);
	top = rotate(top, obj.rotation);
	center = (double[5]){1, 3, center[2] + obj.pos.x, center[3] + obj.pos.y,
		center[4] + obj.pos.z};
	top = (double[5]){1, 3, top[2] + obj.pos.x, top[3] + obj.pos.y,
		top[4] + obj.pos.z};
	if (!(center[3] <= point.y && point.y <= top[3]) &&
			!(top[3] <= point.y && point.y <= center[3]))
		return (0);
	coef_cone = fabs(height / width);
	coef_pt = fabs(top[3] - point.y * (obj.size.width / (top[3] - center[3]));
	if (coef_pt <= coef_cone))
		return (1);
	return (0);
}

int		ft_col_cylinder(t_object obj, t_coord point)
{
	double	*center;
	double	*top;
	double	*perp;
	double	ratio;

	center = (double[5]){1, 3, -obj.size.height / 2, 0};
	top = (double[5]){1, 3, 0, obj.size.height / 2, 0};
	center = rotate(center, obj.rotation);
	top = rotate(top, obj.rotation);
	center = (double[5]){1, 3, center[2] + obj.pos.x, center[3] +
		obj.pos.y, center[4] + obj.pos.z};
	top = (double[5]){1, 3, top[2] + obj.pos.x, top[3] + obj.pos.y,
		top[4] + obj.pos.z};
	if (!(center[3] <= point.y && point.y <= top[3]) ||
			!(top[3] <= point.y && point.y <= center[3]))
		return (0);
	ratio = (point.y - center[3]) / (center[3] - obj.pos.y);
	perp = (double[5]){1, 3, center[2] + ratio * (center[2] - obj.pos.x), point.y, center[4] + ratio * (center[4] - obj.pos.z)};
	if (sqrt(pow(perp[2] - point.x ,2) + pow(perp[3] - point.y ,2) +
				pow(perp[4] - point.z ,2)) <= width)
		return (1);
	return (0);
}

int main()
{
	t_object	cone;
	t_object	cylinder;
	t_object	plan;
	t_object	sphere;
	t_coord		point;

	cone.height = 10;
	cone.width = 2;
	cone.pos = (t_coord){5, 12, 8};
	cone.rotation = (t_rotation){0, 0, 0};
	point = (t_coord){3, 7, 8};

	cylinder.height = 10;
	cylinder.width = 2;
	cylinder.pos = (t_coord){5, 12, 8};
	cylinder.rotation = (t_rotation){0, 0, 0};
	point = (t_coord){};

	plan.height = ;
	plan.width = ;
	plan.depth = ;
	plan.pos = (t_coord){};
	plan.rotation = (t_rotation){};
	point = (t_coord){};

	sphere.height = ;
	sphere.pos = ;
	return (0);
}
