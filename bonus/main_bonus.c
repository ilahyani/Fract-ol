/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:34:02 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/28 15:36:02 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	t_vars vars;

	ft_init(&vars);
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "-t", 2))
		{
			multibrot(&vars);
			mlx_hook(vars.window, 6, 0, mouse_mvmnt, &vars);
			mlx_mouse_hook(vars.window, mouse_hook, &vars);
			mlx_hook(vars.window, 17, 0, close_window, &vars);
			mlx_hook(vars.window, 2, 0, escape, &vars);
			mlx_loop_hook(vars.mlx_pointer, multibrot, &vars);
			mlx_loop(vars.mlx_pointer);
		}
		else
			ft_printf("Invalid Parameter, Please try:\n-t for Multibrot Set\n");
	}
	else if (argc == 1)
		ft_printf("Missing Parameters, Please try:\n-t for Multibrot Set\n");
	else
		ft_printf("Invalid Parameters, Please try:\n-t for Multibrot Set\n");
	return (0);
}
