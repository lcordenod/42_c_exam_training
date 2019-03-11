/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:32:32 by lcordeno          #+#    #+#             */
/*   Updated: 2019/03/11 19:04:20 by lcordeno         ###   ########.fr       */
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
		lst_tmp = lst->next;
		while (lst_tmp)
		{
			if (cmp(lst->data, lst_tmp->data) == 0)
			{
				temp = lst->data;
				lst->data = lst_tmp->data;
				lst_tmp->data = temp;
			}
			lst_tmp = lst_tmp->next;
		}
		lst = lst->next;
	}
	lst = list;
	return (lst);
}
