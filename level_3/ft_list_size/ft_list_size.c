/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:19:12 by lcordeno          #+#    #+#             */
/*   Updated: 2019/01/26 18:38:12 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int count;
	t_list *list;

	count = 0;
	list = begin_list;
	while (list->next != 0)
	{
		count++;
		list = list->next;
	}
	return (count);
}
