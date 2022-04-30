/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <ilahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:34:02 by ilahyani          #+#    #+#             */
/*   Updated: 2022/04/28 19:05:13 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	error_message(int i)
{
	if (i == 0)
	{
		ft_printf("Invalid Parameter, Please try:\n");
		ft_printf("-t for Multibrot Set\n");
	}
	else if (i == 1)
	{
		ft_printf("Missing Parameter, Please try:\n");
		ft_printf("-t for Multibrot Set\n");
	}
	else
	{
		ft_printf("Too many Parameters, Please try:\n");
		ft_printf("-t for Multibrot Set\n");
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	ft_init(&vars);
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "-t", ft_strlen(argv[1])))
			draw_multibrot(&vars);
		else
			error_message(0);
	}
	else if (argc == 1)
		error_message(1);
	else
		error_message(2);
	//Destroy the window the free mlx_ptr
	return (0);
}
