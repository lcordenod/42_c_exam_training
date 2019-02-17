/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:03:37 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/17 12:30:33 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		ft_putchar(nbr + 48);
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac >= 2)
	{
		while (av[i])
			i++;
		ft_putnbr(i - 1);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
