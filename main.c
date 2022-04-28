/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:09:13 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/28 22:57:39 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(int i)
{
	if (i == 0)
	{
		ft_printf("Invalid Parameters, Please try:\n");
		ft_printf("-m for Mandelbrot Set\n-j for Julia Set\n");
	}
	else if (i == 1)
	{
		ft_printf("Missing Parameters, Please try:\n");
		ft_printf("-m for Mandelbrot Set\n-j for Julia Set\n");
	}
	else
	{
		ft_printf("Too many Parameters, Please try:\n");
		ft_printf("-m for Mandelbrot Set\n-j for Julia Set\n");
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	ft_init(&vars);
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "-m", 2))
			draw_mandelbrot(&vars);
		else if (!ft_strncmp(argv[1], "-j", 2))
			draw_julia(&vars);
		else
			error_message(0);
	}
	else if (argc == 1)
		error_message(1);
	else
		error_message(2);
	return (0);
}
