/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:06:25 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/15 12:10:12 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_count_words(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] && (str[i] != ' ' && str[i] != '\t'))
		{
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				i++;
			count++;
		}
	}
	return (count);
}

void	word_split(char *str)
{
	int i;
	int j;

	i = 0;
	j = ft_count_words(str);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				write(1, &str[i], 1);
				i++;
			}
			j--;
			if (j > 0)
				write(1, "   ", 3);
		}
		else
		{
			i++;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2 && av[1][0] != '\0')
		word_split(av[1]);
	write(1, "\n", 1);
	return (0);
}
