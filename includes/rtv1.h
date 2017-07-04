/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:54:15 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/06/29 15:01:47 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define WIN_W 1200
# define WIN_H 800
# define IMG_W WIN_W
# define IMG_H WIN_H
# define COLOR 16711680

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
	int			set;
}				t_coord;

typedef struct	s_size
{
	double		height;
	double		width;
	double		depth;
	int			set;
}				t_size;

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

typedef struct	s_light
{
	int			intensity;
	t_coord		pos;
}				t_light;

typedef struct	s_rotation
{
	double		rot_x;
	double		rot_y;
	double		rot_z;
	int			set;
}				t_rotation;

typedef struct	s_object
{
	int			color;
	int			type;
	int			brightness;
	t_size		size;
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
	t_light		*lights;
	t_eye		eye;
}				t_rtv1;

typedef struct	s_win
{
	int			bpp;
	int			endian;
	int			linelen;
	int			width;
	int			height;
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

void	ft_parse(char *file, t_data *data);
void	ft_cast_ray(t_ray *r, t_coord s, t_coord dst);
void	ft_init_ray(t_ray *ray, t_coord *a, t_coord b);
void	ft_init_win(t_data *data);
void	ft_get_dimension(t_object *obj, int fd);
void	ft_get_color(int *color, int fd);
void	ft_get_brightness(int *brightness, int fd);
void	ft_init_ray(t_ray *ray, t_coord *a, t_coord b);
void	ft_init_data(t_data *data);
void	ft_init_objects(char *file, t_rtv1 *rtv1);
void	ft_error(int error);
int		ft_objectid(char *str);
int		ft_check_numbers(char *str);

#endif
