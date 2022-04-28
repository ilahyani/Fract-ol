/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:40:07 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/28 15:36:12 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	multibrot(t_vars *vars)
{
	t_complex	z_cubed;
	t_complex	z;
	t_complex	c;
	int			i;
	
	vars->coordinates.y = 0;
	while (vars->coordinates.y <= 500)
	{
		vars->coordinates.x = 0;
		while (vars->coordinates.x <= 500)
		{
			z.re = (vars->coordinates.x / 500) * (vars->max_re - vars->min_re) + vars->min_re;
			z.im = (vars->coordinates.y / 500) * (vars->max_im - vars->min_im) + vars->min_im;
			c.re = z.re;
			c.im = z.im;
			i = 0;
			while (i < vars->itr && z.re * z.re + z.im * z.im < 4)
			{
				z_cubed.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im;
				z_cubed.im = -1 * z.im * z.im * z.im + 3 * z.re * z.re * z.im;
				z.re =  z_cubed.re + c.re;
				z.im = z_cubed.im + c.im;
				i++;
			}
			if (i == 200)
				my_mlx_pixel_put(&vars->img, vars->coordinates.x, vars->coordinates.y, 0xffffff);
			else
				my_mlx_pixel_put(&vars->img, vars->coordinates.x, vars->coordinates.y,  create_trgb(1, 3, i, i));
			vars->coordinates.x++;
		}
		vars->coordinates.y++;
	}
	mlx_put_image_to_window(vars->mlx_pointer, vars->window, vars->img.pointer, 0, 0);
	return (0);
}
