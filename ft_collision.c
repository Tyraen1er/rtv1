#include "rtv1.h"

double	*ft_add_vector(double *fst, char sign, double *scd, double *res)
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
	return (res);
}

double	ft_norm_vector(double *vector)
{
	return (sqrt(ft_scalar(vector, vector)));
}

double	*ft_normalize_vector(double *vector, double *res)
{
	double norm;

	norm = ft_norm_vector(vector)
	res[0] = vector[0] / norm;
	res[1] = vector[1] / norm;
	res[2] = vector[2] / norm;
	return (res);
}

double	ft_scalar(double *fst, double *scd)
{
	return (fst[0] * scd[0] + fst[1] * scd[1] + fst[2] * scd[2]);
}

double	*ft_vector_product(double *fst, double *scd, double *res)
{
	double	tmp[3];

	tmp[0] = fst[1] * scd[2] - fst[2] * scd[1];
	tmp[1] = fst[2] * scd[0] - fst[0] * scd[2];
	tmp[2] = fst[0] * scd[1] - fst[1] * scd[0];
	res[0] = tmp[0]; 
	res[1] = tmp[1];
	res[2] = tmp[2];
	return (res);
}

double	*ft_matrice_product(double *fst, double *scd, double *res)
{
	double	tmp[9];

	tmp[0] = fst[0] * scd[0] + fst[1] * scd[3] + fst[2] * scd[6];
	tmp[1] = fst[0] * scd[1] + fst[1] * scd[4] + fst[2] * scd[7];
	tmp[2] = fst[0] * scd[2] + fst[1] * scd[5] + fst[2] * scd[8];
	tmp[3] = fst[3] * scd[0] + fst[4] * scd[3] + fst[5] * scd[6];
	tmp[4] = fst[3] * scd[1] + fst[4] * scd[4] + fst[5] * scd[7];
	tmp[5] = fst[3] * scd[2] + fst[4] * scd[5] + fst[5] * scd[8];
	tmp[6] = fst[6] * scd[0] + fst[7] * scd[3] + fst[8] * scd[6];
	tmp[7] = fst[6] * scd[1] + fst[7] * scd[4] + fst[8] * scd[7];
	tmp[8] = fst[6] * scd[2] + fst[7] * scd[5] + fst[8] * scd[8];
	res[0] = tmp[0];
    res[1] = tmp[1];
    res[2] = tmp[2];
    res[3] = tmp[3];
    res[4] = tmp[4];
    res[5] = tmp[5];
    res[6] = tmp[6];
    res[7] = tmp[7];
    res[8] = tmp[8];
	return (res);
}

double	*ft_transpo_matrice(double *mat, double *res)
{
	double	*tmp;

	tmp = (double[9]){mat[0], mat[3], mat[6], mat[1], mat[4], mat[7], mat[2], mat[5], mat[8]};
	res[0] = tmp[0];
	res[1] = tmp[1];
	res[2] = tmp[2];
	res[3] = tmp[3];
	res[4] = tmp[4];
	res[5] = tmp[5];
	res[6] = tmp[6];
	res[7] = tmp[7];
	res[8] = tmp[8];
	return (res);
}

double	*mult_matrice_vector(double *mat, double *vec, double *res)
{
	double	tmp[3];
	tmp[0] = mat[0] * vec[0] + mat[1] * vec[1] + mat[2] * vec[2];
	tmp[1] = mat[3] * vec[0] + mat[4] * vec[1] + mat[5] * vec[2];
	tmp[2] = mat[6] * vec[0] + mat[7] * vec[1] + mat[8] * vec[2];
	res[0] = tmp[0];
	res[1] = tmp[1];
	res[2] = tmp[2];
	return (res);
}

double	*rotate(double *vector, t_rotation rad, double *res)
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
	return (res);
}

double	ft_pipe_col(t_ray ray, t_object pipe)
{
	double	perp[3];
	
	ft_vector_product(ray.vector, pipe.axe ,perp);
	ft_normalize_vector(, perp);
}

double	ft_cylinder_col(t_ray ray, t_object cyl)
{
	if (ft_pipe_col() < 0)
		return (-1);
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
	if ((t = -ft_scalar((double*)&ray.vector, raycenter) - sqrt(delta)) < 0)
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
