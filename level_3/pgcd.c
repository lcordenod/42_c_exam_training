/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:34:16 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/26 17:53:43 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		find_pgcd(int nb1, int nb2)
{
	int pgcd;

	pgcd = nb1 > nb2 ? nb2 : nb1;
	while (nb1 % pgcd || nb2 % pgcd)
		pgcd--;
	return (pgcd);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%i", find_pgcd(atoi(av[1]), atoi(av[2])));
	printf("\n");
	return (0);
}
