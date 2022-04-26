/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:47:47 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/25 15:19:52 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	manderlbrot(t_image *img)
{

	double		x;
	double		y;
	double		a;
	double		b;
	t_complex	z;
	t_complex	c;
	int			itr;

	y = 0;
	while (y <= 500)
	{
		x = 0;
		while (x <= 500)
		{
			itr = 0;
			z.re = (x / 500) * 4 - 2;
			z.im = (y / 500) * 4 - 2;
			c.re = z.re;
			c.im = z.im;
			while (itr < 100 && z.re * z.re + z.im * z.im < 4)
			{
				a = z.re * z.re - z.im * z.im;
				b = 2 * z.re * z.im;
				z.re =  a + c.re;
				z.im = b + c.im;
				itr++;
			}
			if (itr == 100)
				my_mlx_pixel_put(img, x, y, 0xFFFFFF * y);
			else
				my_mlx_pixel_put(img, x, y, itr * itr);
			x++;
		}
		y++;
	}
}
