/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 09:28:14 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/17 13:15:50 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int i;
	int ret;
	int minus;

	i = 0;
	ret = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\r' || str[i] == '\t'
	|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		ret = ret * 10;
		ret += str[i] - '0';
		i++;
	}
	return (ret * minus);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb > 9)
			ft_putnbr(nb / 10);
		nb = nb % 10 + 48;
		write(1, &nb, 1);
	}
}

int		is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / 2))
	{
		if (!(nb % i))
			return (0);
		else
			i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int nb;
	int sum;

	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		sum = 0;
		while (nb > 0)
		{
			if (is_prime(nb--))
				sum += (nb + 1);
		}
		ft_putnbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}
