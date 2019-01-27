/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:42:50 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/18 18:45:06 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_alpha(char c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	else if (c <= 'Z' && c >= 'A')
		return (1);
	return (0);
}

int		is_cap(char c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (is_alpha(av[1][i]))
			{
				if (av[1][i] <= 'Z' && av[1][i] >= 'A')
					av[1][i] += (25 - (int)av[1][i] + 65 - (int)av[1][i] + 65);
				else
					av[1][i] += (25 - (int)av[1][i] + 97 - (int)av[1][i] + 97);
			}
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
