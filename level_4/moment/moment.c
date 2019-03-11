/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:26:12 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/18 14:20:01 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		duration_to_time(unsigned int duration)
{
	unsigned int time;

	time = 0;
	if (duration > 0 && duration < 60)
		time = duration;
	else if (duration >= 60 && duration < 3600)
		time = duration / 60;
	else if (duration >= 3600 && duration < 86400)
		time = duration / 3600;
	else if (duration >= 86400 && duration < 2592000)
		time = duration / 86400;
	else if (duration >= 2592000 && duration < 77760000)
		time = duration / 2592000;
	return (time);
}

char	duration_to_unit(unsigned int duration)
{
	char	unit;

	unit = 's';
	if (duration >= 60 && duration < 3600)
		unit = 'i';
	else if (duration >= 3600 && duration < 86400)
		unit = 'h';
	else if (duration >= 86400 && duration < 2592000)
		unit = 'd';
	else if (duration >= 2592000 && duration < 77760000)
		unit = 'm';
	return (unit);
}

int		calc_len(unsigned int duration)
{
	int txt_len;
	int nb_len;
	int nb;
	int time;
	char unit;

	time = duration_to_time(duration);
	unit = duration_to_unit(duration);
	nb_len = 1;
	nb = time;
	while (nb > 9)
	{
		nb = nb / 10;
		nb_len++;
	}
	txt_len = 0;
	if (time == 0 || time > 1)
		txt_len += 1;
	if (unit == 's')
		txt_len += 12;
	else if (unit == 'i')
		txt_len += 12;
	else if (unit == 'h')
		txt_len += 10;
	else if (unit == 'd')
		txt_len += 9;
	else if (unit == 'm')
		txt_len += 11;
	return (nb_len + txt_len);
}

char	*ft_concat(char *str, char *str2, int idx)
{
	int i;

	i = 0;
	while (str2[i])
	{
		str[idx] = str2[i];
		idx++;
		i++;
	}
	str[idx] = '\0';
	return (str);
}

char	*moment(unsigned int duration)
{
	char *str;
	int nb_len;
	int nb;
	int i;
	char c;

	c = duration_to_unit(duration);
	if (!(str = (char*)malloc(sizeof(char) * (calc_len(duration) + 1))))
		return (0);
	nb_len = 1;
	nb = duration_to_time(duration);
	while (nb > 9)
	{
		nb = nb / 10;
		nb_len++;
	}
	i = nb_len;
	nb = duration_to_time(duration);
	while (i > 0)
	{
		str[i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	nb = duration_to_time(duration);
	if (c == 's' && (nb == 0 || nb > 1))
		str = ft_concat(str, " seconds ago.", nb_len);
	else if (c == 's')
		str = ft_concat(str, " second ago.", nb_len);
	else if (c == 'i' && (nb == 0 || nb > 1))
		str = ft_concat(str, " minutes ago.", nb_len);
	else if (c == 'i')
		str = ft_concat(str, " minute ago.", nb_len);
	else if (c == 'h' && (nb == 0 || nb > 1))
		str = ft_concat(str, " hours ago.", nb_len);
	else if (c == 'h')
		str = ft_concat(str, " hour ago.", nb_len);
	else if (c == 'd' && (nb == 0 || nb > 1))
		str = ft_concat(str, " days ago.", nb_len);
	else if (c == 'd')
		str = ft_concat(str, " day ago.", nb_len);
	else if (c == 'm' && (nb == 0 || nb > 1))
		str = ft_concat(str, " months ago.", nb_len);
	else if (c == 'm')
		str = ft_concat(str, " month ago.", nb_len);
	return (str);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s\n", moment(atoi(av[1])));
	}
	return (0);
}
