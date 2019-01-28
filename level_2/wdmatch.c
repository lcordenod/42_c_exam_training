/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:25:27 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/23 14:41:05 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
			while ((av[1][i] != av[2][j]) && av[2][j])
				j++;
			if (av[1][i] == av[2][j])
				write(1, &av[1][i], 1);
			j++;
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
