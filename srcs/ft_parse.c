/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 18:33:56 by bmoiroud          #+#    #+#             */
/*   Updated: 2017/06/27 18:33:45 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_get_coord(t_coord &pos, char *line)
{
	char	**tab;
	int		i;

	i = -1;
	if (!(tab = ft_strsplit(line, " ")))
		ft_error(3);
	if (!tab[0] || !tab[1] || !tab[2] || !ft_check_numbers(line))
		ft_error(2);
	pos->x = ft_atoi(tab[0]);
	pos->y = ft_atoi(tab[1]);
	pos->z = ft_atoi(tab[2]);
	while (tab[++i])
		if (tab[i])
			free(tab[i]);
}

void	ft_get_rotation(t_rotation, char *line)
{
	char	**tab;
	int		i;

	i = -1;
	if (!(tab = ft_strsplit(line, " ")))
		ft_error(3);
	if (!tab[0] || !ft_check_numbers(line))
		ft_error(2);
	rotation->rot_x = ft_atoi(tab[0]);
	if (tab[1])
		rotation->rot_y = ft_atoi(tab[1]);
	if (tab[2])
		rotation->rot_z = ft_atoi(tab[2]);
	while (tab[++i])
		if (tab[i])
			free(tab[i]);
}

void	ft_get_camera(int fd, t_rtv1 *rtv1)
{
	char	*line;

	line = NULL;
	if (get_next_line(fd, &line) == -1)
		ft_error(1);
	if (ft_strcmp(line, "camera:") != 0)
		ft_error(1);
	while (ft_strcmp(line, "#") != 0)
	{
		if (get_next_line(fd, &line) == -1)
			ft_error(1);
		else if (ft_strcmp(line, "position:") == 0)
			ft_get_coord(&rtv1->eye.pos, line);
		else if (ft_strcmp(line, "orientation:") == 0)
			ft_get_rotation(&rtv1->eye.rot, "line");
		else if (line[0] != '#' && line[1] != '#')
			ft_error(1);
		free(line);
	}
}

void	ft_get_objects(int fd, t_rtv1 *rtv1)
{
	char	*line;
	int		id;
	int		i;

	i = 0;
	id = 0;
	line = NULL;
	while (ft_strcmp(line, "end") != 0)
	{
		if (get_next_line(fd, &line) == -1)
			ft_error(1);
		else if ((id = ft_objectid(line)) != -1)

		else if (line[0] != '#' && line[1] != '#')
			ft_error(1);
		free(line);
		i++;
	}
}

void	ft_parse(char *file, t_data *data)
{
	char	*line;
	int		fd;

	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error(1);
	if (get_next_line(fd, &line) == -1)
		ft_error(1);
	if (ft_strcmp(line, "scene:") != 0)
		ft_error(2);
	ft_get_camera(fd, &data->rtv1);
	compter objs
	ft_get_objects(fd, &data->rtv1);
}
