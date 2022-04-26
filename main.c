/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:49:17 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/25 23:04:23 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void	*mlx_pointer;
	void	*window;
	t_image img;
	
	mlx_pointer = mlx_init();
	window = mlx_new_window(mlx_pointer, 500, 500, "Mandelbrot");
	img.pointer = mlx_new_image(mlx_pointer, 500, 500);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);
	manderlbrot(&img);
	mlx_put_image_to_window(mlx_pointer, window, img.pointer, 0, 0);
	mlx_loop(mlx_pointer);
}
