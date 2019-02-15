/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <lcordeno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 08:41:24 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/15 12:01:28 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_count_words(char *str)
{
    int count;
    int i;
    int j;

    count = 0;
    i = 0;
    j = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] && str[i] != ' ' && str[i] != '\t')
        {
            while (str[i] && str[i] != ' ' && str[i] != '\t')
                i++;
            count++;
        }
    }
    return (count - 1);
}

int ft_epur_str(char *str)
{
    int i;
    int words;

    i = 0;
    words = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
        {
            write(1, &str[i], 1);
            i++;
        }
        words++;
        if (words <= ft_count_words(str))
            write(1, " ", 1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2)
        ft_epur_str(av[1]);
    write(1, "\n", 1);
}
