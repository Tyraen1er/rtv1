/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:54:15 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/06/27 19:16:22 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include <stdio.h>
# include <pthread.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_ray
{
	double		dx;
	double		dy;
	double		dz;
	double		sx;
	double		sy;
	double		sz;
	double		err;
	double		e2;
}				t_ray;

typedef struct	s_rotation
{
	double		rot_x;
	double		rot_y;
	double		rot_z;
}				t_rotation;

typedef struct	s_object
{
	int			color;
	int			type;
	double		height;
	double		width;
	double		depth;
	t_coord		pos;
	t_rotation	rotation;
}				t_object;

typedef struct	s_eye
{
	t_coord		pos;
	t_rotation	rot;
}				t_eye;

typedef struct	s_rtv1
{
	t_object	*objects;
	t_eye		eye;
}				t_rtv1;

typedef struct	s_win
{
	int			bpp;
	int			endian;
	int			linelen;
	char		*data;
	void		*img;
	void		*mlx;
	void		*win;
}				t_win;

typedef struct	s_data
{
	t_win		win;
	t_rtv1		rtv1;
}				t_data;

void	ft_cast_ray(t_ray *r, t_coord s, t_coord dst);
void	ft_init_ray(t_ray *ray, t_coord *a, t_coord b);
void	ft_init_data(t_data *data);

#endif
