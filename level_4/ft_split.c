/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:14:08 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/17 17:46:16 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

	i = 0;
	if (ac == 2)
	{
		tab_str = ft_split(av[1]);
		while (tab_str[i])
		{
			printf("tab[%d] = %s\n", i, tab_str[i]);
			i++;
		}
	}
	return (0);
}
