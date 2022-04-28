/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:28:17 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/28 19:12:49 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_vars *vars)
{
	manderlbrot(vars);
	mlx_hook(vars->window, 6, 0, mouse_mvmnt, vars);
	mlx_mouse_hook(vars->window, mouse_hook, vars);
	mlx_hook(vars->window, 17, 0, close_window, vars);
	mlx_hook(vars->window, 2, 0, escape, vars);
	mlx_loop_hook(vars->mlx_ptr, manderlbrot, vars);
	mlx_loop(vars->mlx_ptr);
}

void	draw_julia(t_vars *vars)
{
	julia(vars);
	mlx_hook(vars->window, 6, 0, mouse_mvmnt, vars);
	mlx_mouse_hook(vars->window, mouse_hook, vars);
	mlx_hook(vars->window, 17, 0, close_window, vars);
	mlx_hook(vars->window, 2, 0, escape, vars);
	mlx_loop_hook(vars->mlx_ptr, julia, vars);
	mlx_loop(vars->mlx_ptr);
}

void	ft_init(t_vars *vars)
{
	vars->c.re = -0.7269;
	vars->c.im = 0.1889;
	vars->max_i = 2;
	vars->min_i = -2;
	vars->max_r = 2;
	vars->min_r = -2;
	vars->itr = 200;
	vars->mlx_ptr = mlx_init();
	vars->window = mlx_new_window(vars->mlx_ptr, 500, 500, "fractol");
	vars->img.ptr = mlx_new_image(vars->mlx_ptr, 500, 500);
	vars->img.pxls = mlx_get_data_addr(vars->img.ptr, &vars->img.bpp,
			&vars->img.l_size, &vars->img.endian);
}

int	ft_zoom(int x, int y, int keycode, t_vars *vars)
{
	double		k;
	t_complex	mouse;

	if (keycode == 4)
	{
		k = 1.1;
		vars->itr += 5;
	}
	else
		k = 0.9;
	mouse.re = x / (500 / (vars->max_r - vars->min_r)) + vars->min_r;
	mouse.im = y / (500 / (vars->max_i - vars->min_i)) + vars->min_i;
	vars->min_r = mouse.re + (vars->min_r - mouse.re) * k;
	vars->max_r = mouse.re + (vars->max_r - mouse.re) * k;
	vars->min_i = mouse.im + (vars->min_i - mouse.im) * k;
	vars->max_i = mouse.im + (vars->max_i - mouse.im) * k;
	return (0);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pxls + (y * img->l_size + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
