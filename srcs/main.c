/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:52:43 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/06/23 20:56:18 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void testraycasting()
{
	t_ray ray;
	t_coord src;
	t_coord dst;

	src.x = 0;
	src.y = 0;
	src.z = 0;
	dst.x = 10;
	dst.y = 10;
	dst.z = 10;
	ft_cast_ray(&ray, src, dst);
}

void	ft_error(int error)
{
	if (error == 0)
		ft_putstr("usage:\n\t./rtv1 <fichier>\n");
	else if (error == 1)
		ft_putstr("error: invalid file\n");
	else if (error == 2)
		ft_putstr("error: invalid scene\n");
	else if (error == 3)
		ft_putstr("malloc error\n");
	exit(EXIT_FAILURE);
}

int		main(int ac, char** av)
{
	t_data	data;

	ft_bzero(data, sizeof(t_data));
	if (ac < 2 || ac > 2)
		ft_error(0);
	else if (av[1] == NULL)
		ft_error(1);
	ft_init_data(&data);
	ft_parse(av[1], &data);
	return 0;
}
