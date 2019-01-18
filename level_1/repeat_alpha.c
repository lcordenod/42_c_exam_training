/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 10:04:40 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/18 10:46:12 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*repeat_alpha(char *str)
{
	int i;
	char *str2;

	i = 0;
	while (str[i])
	{
		if (str[i] => 'a' && str[i] =< 'z')
	}
	return (str2);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}
