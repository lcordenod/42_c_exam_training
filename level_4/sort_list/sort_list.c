/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:32:32 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/17 18:48:13 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *list;
	t_list *lst_tmp;
	int temp;

	list = lst;
	while (lst)
	{
		lst_tmp = lst;
		while (lst_tmp->next)
		{
			if (cmp(lst_tmp->data, lst_tmp->next->data) == 0)
			{
				temp = lst_tmp->next->data;
				lst_tmp->next->data = lst_tmp->data;
				lst_tmp->data = temp;
			}
			lst_tmp = lst_tmp->next;
		}
		lst = lst->next;
	}
	return (list);
}
