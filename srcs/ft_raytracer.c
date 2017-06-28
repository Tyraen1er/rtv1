/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 15:05:04 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/06/23 17:59:00 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		ft_check_coord(t_coord pos, t_coord dst)
{
	if (pos.x == dst.x && pos.y == dst.y && pos.z == dst.z)
		return (1);
	if (pos.x - 10 > dst.x || pos.y - 10 > dst.y || pos.z - 10 > dst.z)
	{
		printf("pas bon\n");
		return (1);
	}
	return (0);
}

void	ft_cast_ray(t_ray *r, t_coord s, t_coord dst)
{
	t_ray		*ray;

	ray = r;
	ft_init_ray(ray, &s, dst);
	while (1)
	{
		if (ft_check_coord(s, dst))
			break ;
		ray->e2 = ray->err;
		printf("x: %d\ty: %d\tz: %d\te2: %d\n", s.x, s.y, s.z, ray->e2);
		if (ray->e2 > -ray->dx)
		{
			ray->err -= ray->dx;
			s.x += ray->sx;
		}
		if (ray->e2 < ray->dy)
		{
			ray->err += ray->dy;
			s.y += ray->sy;
		}
		if (ray->e2 < ray->dz)
		{
			ray->err += ray->dz;
			s.z += ray->sz;
		}
	}
}
