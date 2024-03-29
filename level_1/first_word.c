/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:18:14 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/17 12:25:16 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	int checkempty;
	int start;
	int end;

	start = 0;
	checkempty = 0;
	while (av[1][checkempty])
		checkempty++;
	if (ac == 2)
	{
		while (av[1][start] == ' ' || av[1][start] == '\t')
			start++;
		if (start != checkempty)
		{
			end = start;
			while (av[1][end] != ' ' && av[1][end] != '\t')
			{
				write(1, &av[1][end], 1);
				end++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
