/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:51:31 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/20 19:16:59 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int result;

	result = 0;
	if (ac == 4)
	{
		if (av[2][0] == '+')
			result = atoi(av[1]) + atoi(av[3]);
		else if (av[2][0] == '-')
			result = atoi(av[1]) - atoi(av[3]);
		else if (av[2][0] == '/')
			result = atoi(av[1]) / atoi(av[3]);
		else if (av[2][0] == '*')
			result = atoi(av[1]) * atoi(av[3]);
		printf("%i", result);
	}
	printf("\n");
	return (0);
}
