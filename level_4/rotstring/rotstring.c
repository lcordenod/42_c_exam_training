/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:54:21 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/17 18:05:20 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_count_words(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str && (*str != ' ' && *str != '\t'))
		{
			while (*str && *str != ' ' && *str != '\t')
				str++;
			count++;
		}
	}
	return (count);
}

char	*word_to_tab(char *str, int start, int end)
{
	char *elem;
	int i;

	i = 0;
	if (!(elem = (char*)malloc(sizeof(char) * (end - start) + 2)))
		return (0);
	while (start <= end)
	{
		elem[i] = str[start];
		start++;
		i++;
	}
	elem[i] = '\0';
	return (elem);
}

char	**ft_split(char *str)
{
	char **tab;
	int i;
	int j;
	int k;
	int words;

	i = 0;
	j = 0;
	k = 0;
	words = ft_count_words(str);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_count_words(str)) + 1)))
		return (0);
	while (str[j] && i < words)
	{
		while (str[j] == ' ' || str[j] == '\t')
			j++;
		if (str[j] && str[j] != ' ' && str[j] != '\t')
		{
			k = j;
			while (str[k] && str[k] != ' ' && str[k] != '\t')
				k++;
			tab[i] = word_to_tab(str, j, k - 1);
			j = k;
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int		main(int ac, char **av)
{
	char **tab_str;
	int i;

	i = 1;
	if (ac == 2)
	{
		tab_str = ft_split(av[1]);
		while (i < ft_count_words(av[1]))
		{
			ft_putstr(tab_str[i]);
			i++;
			write(1, " ", 1);
		}
		ft_putstr(tab_str[0]);
	}
	write(1, "\n", 1);
	return (0);
}
