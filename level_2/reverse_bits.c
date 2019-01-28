/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:12:09 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/22 19:17:51 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char comp;
	unsigned char rev;

	comp = 1;
	rev = 0;
	while (comp)
	{
		if (comp & octet)
			rev += 128 / comp;
		comp *= 2;
	}
	return (rev);
}
