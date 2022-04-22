#include "fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixels + (y * data->line_size + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(int	lenght);
void	draw_circle(void);
void	draw_triangle(void);

int	main(void)
{
	void	*mlx_pointer;
	void	*window;
	t_image img;
	
	mlx_pointer = mlx_init();
	window = mlx_new_window(mlx_pointer, 1000, 1000, "what do you call a black widow? a window!");
	img.pointer = mlx_new_image(mlx_pointer, 100, 100);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);
	int		i;
	for(i = 0; i <= 100; i++)
		my_mlx_pixel_put(&img, 0, i, 0xFFFFFF);
	mlx_put_image_to_window(mlx_pointer, window, img.pointer, 500, 500);
	mlx_loop(mlx_pointer);
}
