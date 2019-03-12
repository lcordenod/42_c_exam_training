/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:12:54 by lcordeno          #+#    #+#             */
/*   Updated: 2019/03/12 09:12:33 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < size)
	{
		j = i;
		while (j < size - 1)
		{
			if (tab[j + 1] < tab[i])
			{
				temp = tab[i];
				tab[i] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int		main(void)
{
	int i;
	int tab[5];

	tab[0] = 5;
	tab[1] = -10;
	tab[2] = 0;
	tab[3] = 2;
	tab[4] = 3;
	i = 0;
	sort_int_tab(tab, 5);
	while (i < 5)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
	return (0);
}
