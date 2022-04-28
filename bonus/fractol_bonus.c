/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:40:07 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/28 18:57:25 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	t_iterate(t_vars *var)
{
	t_complex	z_cubed;
	t_complex	z;
	t_complex	c;
	int			i;

	z.re = var->pnt.x / (500 / (var->max_r - var->min_r)) + var->min_r;
	z.im = var->pnt.y / (500 / (var->max_i - var->min_i)) + var->min_i;
	c.re = z.re;
	c.im = z.im;
	i = 0;
	while (i < var->itr && z.re * z.re + z.im * z.im < 4)
	{
		z_cubed.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im;
		z_cubed.im = -1 * z.im * z.im * z.im + 3 * z.re * z.re * z.im;
		z.re = z_cubed.re + c.re;
		z.im = z_cubed.im + c.im;
		i++;
	}
	if (i == 200)
		my_mlx_pixel_put(&var->img, var->pnt.x, var->pnt.y, 0xffffff);
	else
		my_mlx_pixel_put(&var->img, var->pnt.x, var->pnt.y, trgb(1, 3, i, i));
	var->pnt.x++;
}

int	multibrot(t_vars *vars)
{
	t_complex	z_cubed;
	t_complex	z;
	t_complex	c;
	int			i;

	vars->pnt.y = 0;
	while (vars->pnt.y <= 500)
	{
		vars->pnt.x = 0;
		while (vars->pnt.x <= 500)
			t_iterate(vars);
		vars->pnt.y++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->window, vars->img.ptr, 0, 0);
	return (0);
}
