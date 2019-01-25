/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:46:57 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/25 15:29:35 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	str_uncap(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

void	str_capfirst(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || (str[i - 1] == ' ' || str[i - 1] == '\t'))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			str_uncap(av[i]);
			str_capfirst(av[i]);
			while (*av[i] == ' ' || *av[i] == '\t')
				av[i]++;
			while (*av[i])
			{
				write(1, &*av[i], 1);
				av[i]++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
