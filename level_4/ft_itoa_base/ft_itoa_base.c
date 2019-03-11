/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:49:59 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/25 18:03:06 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_len(int nb, int baseln)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb)
	{
		nb /= baseln;
		i++;
	}
	return (i);
}

void	filler(char *str, int len, int value, int baseln)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF\0";
	i = 0;
	str[len] = '\0';
	if (value == 0)
		str[0] = '0';
	if (value == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		i = 2;
		value = 147483648;
	}
	if (value < 0)
	{
		str[i] = '-';
		value = -value;
		i++;
	}
	while (len > i)
	{
		str[len - 1] = base[value % baseln];
		value /= baseln;
		len--;
	}
}

char	*ft_itoa_base(int value, int base)
{
	char *str;
	int len;

	if (value < 0 && base != 10)
		value = -value;
	len = ft_len(value, base);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	filler(str, len, value, base);
	return (str);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("ft_itoa_base = %s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	return (0);
}
