/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 10:04:40 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/18 16:33:39 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_letter(char c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	else if (c <= 'z' && c >= 'a')
		return (1);
	return (0);
}

int		is_cap(char letter)
{
	if (letter <= 'Z' && letter >= 'A')
		return (1);
	return (0);
}

int		count_repeat(char letter)
{
	int i;

	i = 0;
	if (is_cap(letter))
		i = (int)letter - 64;
	else
		i = (int)letter - 96;
	return (i);
}

void	repeat_alpha(char *str)
{
	int a;
	int b;

	a = 0;
	while (str[a])
	{
		if (is_letter(str[a]))
		{
			b = 0;
			while (b < count_repeat(str[a]))
			{
				write(1, &str[a], 1);
				b++;
			}
		}
		else
			write(1, &str[a], 1);
		a++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}
