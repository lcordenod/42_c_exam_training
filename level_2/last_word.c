/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:59 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/21 18:12:35 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		main(int ac, char **av)
{
	int checkempty;
	int start;
	int end;

	checkempty = 0;
	start = 0;
	end = ft_strlen(av[1]) - 1;
	while (av[1][checkempty])
		checkempty++;
	if (ac == 2)
	{
		while (av[1][end] == ' ' || av[1][end] == '\t')
			end--;
		if (start != checkempty)
		{
			start = end;
			while (av[1][start] != ' ' && av[1][start] != '\t')
				start--;
		}
		while (++start <= end)
			write(1, &av[1][start], 1);
	}
	write(1, "\n", 1);
	return (0);
}
