/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:57:52 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/17 11:58:55 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int		*ft_range(int start, int end)
{
	int *tab;
	int i;

	i = 0;
	if (end > start)
	{
		if (!(tab = (int*)malloc(sizeof(int) * (end - start))))
			return (0);
		while (start <= end)
		{
			tab[i] = start;
			start++;
			i++;
		}
	}
	else
	{
		i = 0;
		if (!(tab = (int*)malloc(sizeof(int) * (start - end))))
			return (0);
		while (end <= start)
		{
			tab[i] = start;
			start--;
			i++;
		}
	}
	return(tab);
}

int		main(int ac, char **av)
{
	int *tab;
	int i;

	i = 0;
	if (ac >= 2)
	{
		tab = ft_range(atoi(av[1]), atoi(av[2]));
		while (i <= (atoi(av[2]) - atoi(av[1])))
		{
			printf("tab[%d] %d\n", i, tab[i]);
			i++;
		}
	}
	return (0);
}
