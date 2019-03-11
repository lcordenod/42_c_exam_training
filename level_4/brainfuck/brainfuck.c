/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:26:12 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/25 12:08:12 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_brainfuck(char *bfck)
{
	char *str;
	int i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * 2048)))
		return (-1);
	while (i < 2048)
	{
		str[i] = 0;
		i++;
	}
	i = 0;
	while (*bfck)
	{
		if (*bfck == '>')
			str++;
		else if (*bfck == '<')
			str--;
		else if (*bfck == '+')
			(*str)++;
		else if (*bfck == '-')
			(*str)--;
		else if (*bfck == '.')
			ft_putchar(*str);
		else if (*bfck == '[' && *str == 0)
		{
			i++;
			while (i != 0)
			{
				bfck++;
				if (*bfck == '[')
					i++;
				else if (*bfck == ']')
					i--;
			}
		}
		else if (*bfck == ']' && *str != 0)
		{
			i++;
			while (i != 0)
			{
				bfck--;
				if (*bfck == ']')
					i++;
				else if (*bfck == '[')
					i--;
			}
		}
		bfck++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
