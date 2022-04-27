/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:39:42 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/27 22:17:12 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	Julia(t_vars *vars)
{
	t_complex	z_squared;
	t_complex	z;
	int	i = 0;

	vars->coordinates.y = 0;
	while (vars->coordinates.y <= 500)
	{
		vars->coordinates.x = 0;
		while (vars->coordinates.x <= 500)
		{
			i= 0;
			z.re = (vars->coordinates.x / 500) * (vars->max_re - vars->min_re) + vars->min_re;
			z.im = (vars->coordinates.y / 500) * (vars->max_im - vars->min_im) + vars->min_im;
			while (i < vars->itr && z.re * z.re + z.im * z.im < 4)
			{
				z_squared.re = z.re * z.re - z.im * z.im;
				z_squared.im = 2 * z.re * z.im;
				z.re =  z_squared.re + vars->c.re;
				z.im = z_squared.im + vars->c.im;
				i++;
			}
			if (i == 200)
				my_mlx_pixel_put(&vars->img, vars->coordinates.x, vars->coordinates.y,  0);
			else
				my_mlx_pixel_put(&vars->img, vars->coordinates.x, vars->coordinates.y,  create_trgb(1, 0, i, i * 2));
			vars->coordinates.x++;
		}
		vars->coordinates.y++;
	}
	mlx_put_image_to_window(vars->mlx_pointer, vars->window, vars->img.pointer, 0, 0);
	return (0);
}
