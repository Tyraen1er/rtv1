#include "rtv1.h"

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

double	ft_norm_vector(double *vector)
{
	vector(sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2)));
}

double	ft_scalar(double *fst, double *scd)
{
	return (fst[0] * scd[0] + fst[1] * scd[1] + fst[2] * scd[2]);
}

void	ft_vector_product(double *fst, double *scd, double *res)
{
	res[0] = fst[1] * scd[2] - fst[2] * scd[1];
	res[1] = fst[2] * scd[0] - fst[0] * scd[2];
	res[2] = fst[0] * scd[1] - fst[1] * scd[0];
}

void	ft_matrice_product(double *fst, double *scd, double *res)
{
	res[0] = fst[0] * scd[0] + fst[1] * scd[3] + fst[2] * scd[6];
	res[1] = fst[0] * scd[1] + fst[1] * scd[4] + fst[2] * scd[7];
	res[2] = fst[0] * scd[2] + fst[1] * scd[5] + fst[2] * scd[8];
	res[3] = fst[3] * scd[0] + fst[4] * scd[3] + fst[5] * scd[6];
	res[4] = fst[3] * scd[1] + fst[4] * scd[4] + fst[5] * scd[7];
	res[5] = fst[3] * scd[2] + fst[4] * scd[5] + fst[5] * scd[8];
	res[6] = fst[6] * scd[0] + fst[7] * scd[3] + fst[8] * scd[6];
	res[7] = fst[6] * scd[1] + fst[7] * scd[4] + fst[8] * scd[7];
	res[8] = fst[6] * scd[2] + fst[7] * scd[5] + fst[8] * scd[8];
}

void	ft_transpo_matrice(double *mat, double *res)
{
	res[0] = mat[0];
	res[1] = mat[3];
	res[2] = mat[6];
	res[3] = mat[1];
	res[4] = mat[4];
	res[5] = mat[5];
	res[6] = mat[2];
	res[7] = mat[5];
	res[8] = mat[8];
}

void	*mult_matrice_vector(double *mat, double *vec, double *res)
{
	res[0] = mat[0] * vec[0] + mat[1] * vec[1] + mat[2] * vec[2];
	res[1] = mat[3] * vec[0] + mat[4] * vec[1] + mat[5] * vec[2];
	res[2] = mat[6] * vec[0] + mat[7] * vec[1] + mat[8] * vec[2];
}

void	rotate(double *vector, t_rotation rad, double *res)
{
	double			*rot;
	double			*tmp;

	if (!vector || !res)
		return ;
	rot = (double[9]){1, 0, 0, 0, cos(rad.rot_x), -sin(rad.rot_x),
		0, sin(rad.rot_x), cos(rad.rot_x)};
	mult_matrice_vector(rot, vector, res);
	tmp = (double[3]){res[0], res[1], res[2]};
	rot = (double[9]){cos(rad.rot_y), 0, sin(rad.rot_y), 0, 1, 0,
		-sin(rad.rot_y), 0, cos(rad.rot_y)};
	mult_matrice_vector(rot, tmp, res);
	tmp = (double[3]){res[0], res[1], res[2]};
	rot = (double[9]){cos(rad.rot_z), -sin(rad.rot_z), 0, sin(rad.rot_z),
		cos(rad.rot_z), 0, 0, 0, 1};
	mult_matrice_vector(rot, tmp, res);
}

double	ft_cylinder_col(t_ray ray, t_object cyl)
{
// en cours
	return (0);
}

double	ft_sphere_col(t_ray ray, t_object sphere)
{
	double	delta;
	double	raycenter[3];
	double	t;

	ft_add_vector((double*)&ray.point, '-', (double*)&sphere.pos, raycenter);
	delta = pow(ft_scalar((double*)&ray.vector, raycenter), 2) - pow(ft_norm_vector(raycenter), 2) - pow(sphere.size.height, 2);
	if (delta < 0)
		return (-1);
	if (!delta)
		return (-ft_scalar((double*)&ray.vector, raycenter));
	if ((tmp = -ft_scalar((double*)&ray.vector, raycenter) - sqrt(delta)) < 0)
		return (-ft_scalar((double*)&ray.vector, raycenter) + sqrt(delta));
	return (t);
}

double	ft_plan_col(t_ray ray, t_object plan)
{
	double	norm[3];
	double	trueplan[3];
	double	raycenter[3];

	if (plan.size.height && plan.size.width && plan.size.depth)
		return (ft_cube(ray, plan));
	norm[0] = (!plan.size.height) ? 1 : 0;
	norm[1] = (!plan.size.width) ? 1 : 0;
	norm[2] = (!plan.size.depth) ? 1 : 0;
	rotate((double[3]{norm[0], norm[1], norm[2]}, plan.rotation, norm);
	rotate((double*)&plan.size, plan.rotation, trueplan);
	if (!ft_scalar(ray.vector, norm))
		return (-1);
	ft_add_vector((double*)&plan.pos, '-', (double*)&ray.point, raycenter);
	return (ft_scalar(raycenter, norm) / ft_scalar((double*)&ray.vector, norm));
}

int main()
{
	return (0);
}
