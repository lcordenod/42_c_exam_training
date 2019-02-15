/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <lcordeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:50:46 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/14 14:03:52 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     count_units(int nbr)
{
	int count;

	count = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr >= 10)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int		multip_unit(int unit)
{
	int ret;

	ret = 1;
	while (unit > 0)
	{
		ret *= 10;
		unit--;
	}
	return (ret);
}

char    *ft_itoa(int nbr)
{
	char	*ret;
	int		div;
	int		i;
	int		count;

	i = 0;
	div = multip_unit(count_units(nbr));
	count = count_units(nbr);
	if (!(ret = malloc(sizeof(char) * (count_units(nbr) + 1))))
		return (0);
	if (nbr < 0)
	{
		ret[i] = '-';
		nbr *= -1;
		count++;
		i++;
	}
	while (i <= count)
	{
		ret[i] = (nbr / div) + '0';
		nbr %= div;
		div /= 10;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		printf("itoa = %s\n", ft_itoa(atoi(av[1])));
	return (0);
}
