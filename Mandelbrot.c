/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:47:47 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/27 22:20:11 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	manderlbrot(t_vars *vars)
{
	t_complex	z_squared;
	t_complex	z;
	t_complex	c;
	int			i = 0;
	
	vars->coordinates.y = 0;
	while (vars->coordinates.y <= 500)
	{
		vars->coordinates.x = 0;
		while (vars->coordinates.x <= 500)
		{
			z.re = (vars->coordinates.x / 500) * (vars->max_re - vars->min_re) + vars->min_re;
			z.im = (vars->coordinates.y / 500) * (vars->max_im - vars->min_im) + vars->min_im;
			c.re = z.re;
			i = 0;
			c.im = z.im;
			while (i < vars->itr && z.re * z.re + z.im * z.im < 4)
			{
				z_squared.re = z.re * z.re - z.im * z.im;
				z_squared.im = 2 * z.re * z.im;
				z.re =  z_squared.re + c.re;
				z.im = z_squared.im + c.im;
				i++;
			}
			if (i == 200)
				my_mlx_pixel_put(&vars->img, vars->coordinates.x, vars->coordinates.y, 0);
			else
				my_mlx_pixel_put(&vars->img, vars->coordinates.x, vars->coordinates.y,  create_trgb(1, 3, i, i));
			vars->coordinates.x++;
		}
		vars->coordinates.y++;
	}
	mlx_put_image_to_window(vars->mlx_pointer, vars->window, vars->img.pointer, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	
	vars.max_im = 2;
	vars.min_im = -2;
	vars.max_re = 2;
	vars.min_re = -2;
	vars.itr = 200;
	vars.mlx_pointer = mlx_init();
	vars.window = mlx_new_window(vars.mlx_pointer, 500, 500, "Mandelbrot");
	vars.img.pointer = mlx_new_image(vars.mlx_pointer, 500, 500);
	vars.img.pixels = mlx_get_data_addr(vars.img.pointer, &vars.img.bits_per_pixel, &vars.img.line_size, &vars.img.endian);
	manderlbrot(&vars);
	mlx_hook(vars.window, 6, 0, mouse_mvmnt, &vars);
	mlx_mouse_hook(vars.window, mouse_hook, &vars);
	mlx_hook(vars.window, 17, 0, close_window, &vars);
	mlx_hook(vars.window, 2, 0, escape, &vars);
	mlx_loop_hook(vars.mlx_pointer, manderlbrot, &vars);
	mlx_loop(vars.mlx_pointer);
}
