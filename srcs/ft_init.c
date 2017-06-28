/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 15:07:34 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/06/27 16:58:23 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_init_ray(t_ray *ray, t_coord *a, t_coord b)
{
	ray->dx = abs(b.x - a->x);
	ray->sx = a->x < b.x ? 1 : -1;
	ray->dy = abs(b.y - a->y);
	ray->sy = a->y < b.y ? 1 : -1;
	ray->dz = abs(b.z - a->z);
	ray->sz = a->z < b.z ? 1 : -1;
	ray->e2 = ray->err;
}

void	ft_init_data(t_data *data)
{
	t_win	*win;

	win = &data->win;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIN_W, WIN_H, "RTv1");
	win->img = mlx_new_image(win->mlx, IMG_W, IMG_H);
	win->data = mlx_get_data_addr(win->img, &win->bpp, &win->linelen, \
																&win->endian);
}
