/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:49:17 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/27 19:00:49 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	main(void)
// {
// 	t_vars	vars;
	
// 	vars.max_im = 2;
// 	vars.min_im = -2;
// 	vars.max_re = 2;
// 	vars.min_re = -2;
// 	vars.mlx_pointer = mlx_init();
// 	vars.window = mlx_new_window(vars.mlx_pointer, 500, 500, "Mandelbrot");
// 	vars.img.pointer = mlx_new_image(vars.mlx_pointer, 500, 500);
// 	vars.img.pixels = mlx_get_data_addr(vars.img.pointer, &vars.img.bits_per_pixel, &vars.img.line_size, &vars.img.endian);
// 	manderlbrot(&vars);
// 	mlx_hook(vars.window, 6, 0, mouse_mvmnt, &vars);
// 	mlx_mouse_hook(vars.window, mouse_hook, &vars);
// 	mlx_hook(vars.window, 17, 0, close_window, &vars);
// 	mlx_hook(vars.window, 2, 0, escape, &vars);
// 	mlx_loop_hook(vars.mlx_pointer, manderlbrot, &vars);
// 	mlx_loop(vars.mlx_pointer);
// }

int	main(void)
{
	t_vars	vars;
	
	vars.max_im = 2;
	vars.min_im = -2;
	vars.max_re = 2;
	vars.min_re = -2;
	vars.mlx_pointer = mlx_init();
	vars.window = mlx_new_window(vars.mlx_pointer, 500, 500, "Mandelbrot");
	vars.img.pointer = mlx_new_image(vars.mlx_pointer, 500, 500);
	vars.img.pixels = mlx_get_data_addr(vars.img.pointer, &vars.img.bits_per_pixel, &vars.img.line_size, &vars.img.endian);
	vars.c.re = - 0.7269;
	vars.c.im = 0.1889;
	Julia(&vars);
	mlx_hook(vars.window, 6, 0, mouse_mvmnt, &vars);
	mlx_mouse_hook(vars.window, mouse_hook, &vars);
	mlx_hook(vars.window, 17, 0, close_window, &vars);
	mlx_hook(vars.window, 2, 0, escape, &vars);
	mlx_loop_hook(vars.mlx_pointer, Julia, &vars);
	mlx_loop(vars.mlx_pointer);
}
