/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:01:21 by lcordeno          #+#    #+#             */
/*   Updated: 2019/03/11 15:52:35 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		count_units(int nb)
{
	int		count;

	count = 0;
	if (nb < 0)
		nb *= -1;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int		multip_unit(int unit)
{
	int		ret;

	ret = 1;
	while (unit > 0)
	{
		ret *= 10;
		unit--;
	}
	return (ret);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	int		multip;
	int		i;

	len = count_units(nbr);
	multip = multip_unit(len);
	i = 0;
	if (nbr < 0)
		i = 1;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1 + i))))
		return (0);
	if (nbr == -2147483648)
		str = "-2147483648\0";
	else
	{
		if (nbr < 0)
		{
			nbr *= -1;
			str[0] = '-';
			len++;
		}
		while (i <= len)
		{
			str[i] = (nbr / multip) + '0';
			nbr %= multip;
			multip /= 10;
			i++;
		}
		str[len + 1] = '\0';
	}
	return (str);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		printf("itoa = %s\n", ft_itoa(atoi(av[1])));
	return (0);
}
