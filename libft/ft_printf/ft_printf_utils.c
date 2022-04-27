/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:14:53 by ilahyani          #+#    #+#             */
/*   Updated: 2022/01/02 00:32:39 by ilahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648", len);
	else if (nb < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(nb * -1, len);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48, len);
	else
	{
		ft_putnbr(nb / 10, len);
		ft_putchar(nb % 10 + 48, len);
	}
}

void	ft_putunbr(unsigned int nb, int *len)
{
	if (nb <= 9)
		ft_putchar(nb + 48, len);
	else
	{
		ft_putnbr(nb / 10, len);
		ft_putchar(nb % 10 + 48, len);
	}
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}

void	ft_hex(unsigned long x, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (x <= 15)
		ft_putchar(base[x], len);
	else
	{
		ft_hex(x / 16, len);
		ft_hex(x % 16, len);
	}
}

void	ft_uhex(unsigned long x, int *len)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (x <= 15)
		ft_putchar(base[x], len);
	else
	{
		ft_uhex(x / 16, len);
		ft_uhex(x % 16, len);
	}
}
