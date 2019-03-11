/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:15:15 by lcordeno          #+#    #+#             */
/*   Updated: 2019/03/11 18:50:39 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "t_point.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**make_area(char **zone)
{
	char **area;
	int i;
	int j;

	i = 0;
	area = (char**)malloc(sizeof(*area) * 6);
	area[5] = 0;
	while (i < 5)
	{
		area[i] = (char*)malloc(sizeof(**area) * 9);
		area[i][8] = 0;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 8)
		{
			area[i][j] = zone[i][j];
			j++;
		}
		i++;
	}
	return (area);
}

void	print_tab(char **area)
{
	int i;
	int j;

	i = 0;
	while (area[i])
	{
		j = 0;
		while (area[i][j])
		{
			ft_putchar(area[i][j]);
			j++;
		}
		i++;
		if (area[i])
			ft_putchar('\n');
	}
}

void	filler(char **tab, int y, int x, char c, t_point size)
{
	tab[y][x] = 'F';
	if (y + 1 <= size.y && tab[y + 1][x] == c)
		filler(tab, y + 1, x, c, size);
	if (x + 1 <= size.x && tab[y][x + 1] == c)
		filler(tab, y, x + 1, c, size);
	if (y - 1 <= size.y && tab[y - 1][x] == c)
		filler(tab, y - 1 , x, c, size);
	if (x - 1 <= size.x && tab[y][x + 1] == c)
		filler(tab, y, x - 1, c, size);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	int y;
	int x;
	char c;

	if (!(tab))
		return;
	if (begin.x < 1 || begin.x > size.x || begin.y < 1 || begin.y > size.y)
		return;
	y = begin.y - 1;
	x = begin.x - 1;
	c = tab[y][x];
	filler(tab, y, x, c, size);
}

int		main(void)
{
	char	**area;
	t_point size = { 8, 5 };
	t_point begin = { 2, 2};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001"
	};

	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	ft_putchar('\n');
	print_tab(area);
	return (0);
}
