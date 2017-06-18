/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savebitmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:53:25 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/15 18:55:10 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

typedef struct			s_header_file_bmp
{
	short				bf_type;
	int					bf_size;
	int					bf_offset;
}						t_header_file_bmp;

typedef struct			s_info_bmp
{
	int					info_size;
	int					width;
	int					height;
	short				nb_planes;
	short				bits_per_pixel;
	int					compression;
	int					pic_size;
	int					h_pixel_per_meter;
	int					v_pixel_per_meter;
	int					nb_color_used;
	int					nb_color_important;
	int					*palette;
}						t_info_bmp;

typedef struct			s_bmp
{
	t_header_file_bmp	header;
	t_info_bmp	info;
	char				*picture;
}						t_bmp;

int		ft_save_bitmap(char *file, t_bmp *bmp)
{
	int	a;

	if (!((file[0] == 'B' && file[1] == 'M') ||
				(file[0] == 'B' && file[1] == 'A') ||
				(file[0] == 'C' && file[1] == 'I') ||
				(file[0] == 'C' && file[1] == 'P') ||
				(file[0] == 'I' && file[1] == 'C') ||
				(file[0] == 'P' && file[1] == 'T')))
		return (0);
	else
		bmp->header.bf_type = *((short*)file);
	printf("%x\n%x\n", (*((int*)&file[2]) & 0xFFFFFFFF), *((int*)&file[10]) & 0xFFFFFFFF);
/*	write(1, &bmp->header.bf_type, 2);
	ft_putstr("\ntaille fichier : ");
	bmp->header.bf_size = *((int*)(file + 2));
	ft_putnbr((int)(bmp->header.bf_size));
	bmp->header.bf_offset = *((int*)(file + 10));
	ft_putstr("\noffset : ");
	ft_putnbr(bmp->header.bf_offset);
*/	return (0);
}

int		main(int argc, char **argv)
{
	int		fd_rd[2];
	char	buf[151];
	char	*file;
	char	*tmp;
	t_bmp	picture;

	file = ft_memalloc(1);
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf fichier_file\n");
		return (0);
	}
	if ((fd_rd[0] = open(argv[1], O_RDONLY)) == -1)
	{
		printf("impossible d open\n");
		return (0);
	}
	while ((fd_rd[1] = read(fd_rd[0], buf, 150)) && fd_rd[1] != -1)
	{
		buf[fd_rd[1]] = 0;
		tmp = ft_strjoin(file, buf);
		ft_memdel((void *)&file);
		file = tmp;
	}
	if (fd_rd[1] == -1 || !tmp)
		ft_putstr("error read or display\n");
	if (!ft_save_bitmap(file, &picture))
		ft_putstr("\nTout semble OK patron\n");
	return (0);
}
