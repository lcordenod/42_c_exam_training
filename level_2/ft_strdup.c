/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:44:22 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/21 13:59:28 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if ((cpy = (char*)malloc(sizeof(char) * (len + 1))))
	{
		free(cpy);
		return (0);
	}
	while (i < len)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[len] = '\0';
	return (cpy);
}
