/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 08:38:08 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/17 13:15:38 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_atoi(char *str)
{
	int ret;
	int minus;

	ret = 0;
	minus = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		ret = ret * 10;
		ret += *str - '0';
		str++;
	}
	return (ret * minus);
}

int		ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	{
		if (nbr < 0)
		{
			nbr *= -1;
			write(1, "-", 1);
		}
		if (nbr > 9)
			ft_putnbr(nbr / 10);
		nbr = nbr % 10 + 48;
		write(1, &nbr, 1);
	}
	return (0);
}

int		is_prime(int nb)
{
	int i;

	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		add_prime(int nb)
{
	int i;
	int ret;

	i = 2;
	ret = 0;
	while (i <= nb)
	{
		if (is_prime(i))
			ret += i;
		i++;
	}
	return (ret);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_putnbr(add_prime(ft_atoi(av[1])));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
