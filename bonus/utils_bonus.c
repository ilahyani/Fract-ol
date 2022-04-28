/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:48:55 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/28 15:36:18 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pixels + (y * img->line_size + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_zoom(int	x, int y, int keycode, t_vars *vars)
{
	double	k;
	t_complex	mouse;

	if (keycode == 4)
	{
		k = 1.1;
		vars->itr += 5;
	}
	else
		k = 0.9;
	mouse.re = x / (500 / (vars->max_re - vars->min_re)) + vars->min_re;
	mouse.im = y / (500 / (vars->max_im - vars->min_im)) + vars->min_im;
	vars->min_re = mouse.re + (vars->min_re - mouse.re) * k;
	vars->max_re = mouse.re + (vars->max_re - mouse.re) * k;
	vars->min_im = mouse.im + (vars->min_im - mouse.im) * k;
	vars->max_im = mouse.im + (vars->max_im - mouse.im) * k;
	return (0);
}

int		mouse_mvmnt(int x, int y, t_vars *vars)
{
	vars->c.re = x / (500 / (vars->max_re - vars->min_re)) + vars->min_re;
	vars->c.im = y / (500 / (vars->max_im - vars->min_im)) + vars->min_im;
	return (0);
}

int		mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 4 || keycode == 5)
		ft_zoom(x, y, keycode, vars);
	return (0);
}

int close_window(void *param)
{
    (void)param;
	ft_printf("Program Exited Successfully\n");
    exit(0);
}
int escape(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
	{
		ft_printf("Program Exited Successfully\n");
    	exit(0);
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_init(t_vars *vars)
{
	vars->c.re = - 0.7269;
	vars->c.im = 0.1889;
	vars->max_im = 2;
	vars->min_im = -2;
	vars->max_re = 2;
	vars->min_re = -2;
	vars->itr = 200;
	vars->mlx_pointer = mlx_init();
	vars->window = mlx_new_window(vars->mlx_pointer, 500, 500, "fractol");
	vars->img.pointer = mlx_new_image(vars->mlx_pointer, 500, 500);
	vars->img.pixels = mlx_get_data_addr(vars->img.pointer, &vars->img.bits_per_pixel, &vars->img.line_size, &vars->img.endian);
}