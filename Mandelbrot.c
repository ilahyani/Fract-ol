/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:47:47 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/27 19:13:06 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	manderlbrot(t_vars *vars)
{
	t_vector	coordinates;
	t_complex	z_squared;
	t_complex	z;
	
	coordinates.y = 0;
	while (coordinates.y <= 500)
	{
		coordinates.x = 0;
		while (coordinates.x <= 500)
		{
			vars->itr = 0;
			z.re = (coordinates.x / 500) * (vars->max_re - vars->min_re) + vars->min_re;
			z.im = (coordinates.y / 500) * (vars->max_im - vars->min_im) + vars->min_im;
			vars->c.re = z.re;
			vars->c.im = z.im;
			while (vars->itr < 200 && z.re * z.re + z.im * z.im < 4)
			{
				z_squared.re = z.re * z.re - z.im * z.im;
				z_squared.im = 2 * z.re * z.im;
				z.re =  z_squared.re + vars->c.re;
				z.im = z_squared.im + vars->c.im;
				vars->itr++;
			}
			if (vars->itr == 200)
				my_mlx_pixel_put(&vars->img, coordinates.x, coordinates.y, create_trgb(0, 0, 0, 0));
			else
				my_mlx_pixel_put(&vars->img, coordinates.x, coordinates.y,  create_trgb(1, vars->itr, vars->itr*2, vars->itr*3));
			coordinates.x++;
		}
		coordinates.y++;
	}
	mlx_put_image_to_window(vars->mlx_pointer, vars->window, vars->img.pointer, 0, 0);
	return (0);
}
