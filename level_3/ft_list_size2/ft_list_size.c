/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:52:25 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/16 17:57:06 by lcordeno         ###   ########.fr       */
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
		list = list->next;
		count++;
	}
	return (count);
}
