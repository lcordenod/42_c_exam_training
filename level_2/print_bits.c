/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 09:11:01 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/22 19:10:32 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
void	print_bits(unsigned char octet)
{
	int		i;

	i = 8;
	while (i--)
		write(1, (octet & 1 << i ? "1" : "0"), 1);
}
*/
void	print_bits(unsigned char octet)
{
	unsigned char comp;

	comp = 128;
	while (comp >= 1)
	{
		if (comp & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		comp /= 2;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_bits(av[1][0]);
	return (0);
}
