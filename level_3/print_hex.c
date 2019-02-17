/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:26:28 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/17 14:09:07 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_printhex(int nb)
{
	if (nb >= 16)
		ft_printhex(nb / 16);
	if (nb % 16 < 10)
		ft_putchar((nb % 16) + 48);
	else
		ft_putchar((nb % 16) - 10 + 97);
	return (0);
}

int		ft_atoi_printhex(const char *str, int str_base)
{
	int ret;

	ret = 0;
	while (*str == ' ' || *str == '\f' || *str == '\r' || *str == '\t' ||
	*str == '\n' || *str == '\v')
		str++;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		else
		{
			ret = ret * str_base + (*str - 48);
			str++;
		}
	}
	return (ret);
}

int		main(int ac, char **av)
{
	int nb;

	if (ac == 2)
	{
		if ((nb = ft_atoi_printhex(av[1], 10)) != -1)
			ft_printhex(nb);
	}
	write(1, "\n", 1);
	return (0);
}
