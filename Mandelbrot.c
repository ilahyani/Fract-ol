/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:47:47 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/28 22:45:04 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	m_iterate(t_vars *var)
{
	t_complex	z_squared;
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
		z_squared.re = z.re * z.re - z.im * z.im;
		z_squared.im = 2 * z.re * z.im;
		z.re = z_squared.re + c.re;
		z.im = z_squared.im + c.im;
		i++;
	}
	if (i == 200)
		my_mlx_pixel_put(&var->img, var->pnt.x, var->pnt.y, 0xffffff);
	else
		my_mlx_pixel_put(&var->img, var->pnt.x, var->pnt.y, trgb(1, 0, i, i));
	var->pnt.x++;
}

int	manderlbrot(t_vars *var)
{
	var->pnt.y = 0;
	while (var->pnt.y <= 500)
	{
		var->pnt.x = 0;
		while (var->pnt.x <= 500)
			m_iterate(var);
		var->pnt.y++;
	}
	mlx_put_image_to_window(var->mlx_ptr, var->window, var->img.ptr, 0, 0);
	return (0);
}
