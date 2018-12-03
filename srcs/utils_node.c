/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:19:52 by fhong             #+#    #+#             */
/*   Updated: 2018/12/03 00:20:47 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dnode	*node_add_last(t_dnode *begin_node, t_dnode *new_node)
{
	t_dnode *tmp;

	if (begin_node == NULL)
		return (new_node);
	tmp = begin_node;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (begin_node);
}

void	test_print(t_dnode *node)
{
	while (node)
	{
		ft_printf("%s\n", node->dir_name);
		node = node->next;
	}
}
