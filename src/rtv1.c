#include "rtv1.h"

int main()
{
	t_mlx	mlx;
	int		bpp;
	int		s_l;
	int		endian;

	bpp = 0;
	s_l = 0;
	endian = 0;
	if (!(mlx.init = mlx_init()) ||
			!(mlx.win = mlx_new_window(mlx.init, 1000, 1000, "fractal 42")) ||
			!(mlx.image = mlx_new_image(mlx.init, 1000, 1000)) ||
			!(mlx.addr = 
				(void*)mlx_get_data_addr(mlx.image, &(bpp), &(s_l), &(endian))))
		exit(3);
	ft_putstr("coucou\n");
	mlx_loop(mlx.init);
	return (0);
}
