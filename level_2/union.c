/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:35:44 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/23 12:17:58 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		c_in_str(char *str, char c, int idx)
{
	int i;

	i = 0;
	while (str[i] && (i < idx))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (c_in_str(av[1], av[1][i], i) == 0)
				write(1, &av[1][i], 1);
			i++;
		}
		while (av[2][j])
		{
			if ((c_in_str(av[1], av[2][j], ft_strlen(av[1])) == 0) &&
			c_in_str(av[2], av[2][j], j) == 0)
				write(1, &av[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
