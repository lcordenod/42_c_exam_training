/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:33:52 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/15 11:55:32 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
	printf("count = %d", count);
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
			write(1, " ", 1);
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
