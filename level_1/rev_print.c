/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:29:57 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/18 15:40:21 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	int i;

	if (ac == 2)
	{
		i = ft_strlen(av[1]);
		while (i--)
			write(1, &av[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
