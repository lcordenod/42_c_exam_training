/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:04:09 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/14 14:57:26 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		prime_div(int nb)
{
	int i;
	
	i = 2;
	while (nb > 1)
	{
		while (nb % i != 0)
			i++;
		printf("%d", i);
		nb = nb / i;
		if (nb > 1)
			printf("*");
	}
	return (i);
}

int		is_prime(int nb)
{
	int i;

	i = 2;
	while (nb % i != 0 && i <= nb)
		i++;
	if (i == nb)
		return (1);
	else
		return (0);

}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (atoi(av[1]) == 1)
			printf("1");
		else if (is_prime(atoi(av[1])))
			printf("%s", av[1]);
		else
			prime_div(atoi(av[1]));
	}
	printf("\n");
	return (0);
}
