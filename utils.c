/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:52:03 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/28 18:58:43 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_mvmnt(int x, int y, t_vars *vars)
{
	vars->c.re = x / (500 / (vars->max_r - vars->min_r)) + vars->min_r;
	vars->c.im = y / (500 / (vars->max_i - vars->min_i)) + vars->min_i;
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 4 || keycode == 5)
		ft_zoom(x, y, keycode, vars);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	ft_printf("Program Exited Successfully\n");
	exit(0);
}

int	escape(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
	{
		ft_printf("Program Exited Successfully\n");
		exit(0);
	}
	return (0);
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
