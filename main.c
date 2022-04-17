/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:53:51 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/17 15:45:12 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_pixel(char *pxl, t_color color)
{
	pxl[0] = color.b;
	pxl[1] = color.g;
	pxl[2] = color.r;
	pxl[3] = color.a;
}

void	color_img(t_image *img, t_color color)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->size.y)
	{
		x = 0;
		while (x < img->size.x)
		{
			color_pixel(img->pixels[x * 4 + img->line_size * y], color);
			x++; 
		}
		y++;
	}
}

int	main(void)
{
	void	*mlx_pointer;
	void	*window;
	t_image img;
	
	mlx_pointer = mlx_init();
	window = mlx_new_window(mlx_pointer, 500, 500, "what do you call a black widow? a window!");
	img.pointer = mlx_new_image(mlx_pointer, 40, 40);
	img.size.x = 40;
	img.size.y = 40;
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);
	mlx_put_image_to_window(mlx_pointer, window, img.pointer, 250, 250);
	//int		i;
	// for (i = 0; i < 500; i++)
	//  	mlx_pixel_put(mlx_pointer, window, i, i, 0xFFFFFF);
	//mlx_pixel_put(mlx_pointer, img.pointer, 20, 20, 0xFFFFFF);
	mlx_loop(mlx_pointer);
}