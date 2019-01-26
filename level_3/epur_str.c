/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 08:54:46 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/25 16:27:41 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_count_words(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == '\t' || *str == ' ')
			str++;
		if (*str && (*str != '\t' && *str != ' '))
		{
			while (*str && (*str != '\t' && *str != ' '))
				str++;
			count++;
		}
	}
	return (count);
}

void	ft_word_to_tab(char *str)
{
	int i;
	int j;

	i = ft_count_words(str);
	j = 0;
	while (*str)
	{
		while (*str == '\t' || *str == ' ')
			str++;
		while (*str && (*str != '\t' && *str != ' '))
		{
			write(1, &*str, 1);
			str++;
		}
		if (*str != '\0' && j < i - 1)
		{
			write(1, " ", 1);
			j++;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_word_to_tab(av[1]);
	write(1, "\n", 1);
	return (0);
}
