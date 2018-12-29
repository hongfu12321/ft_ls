/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:14:21 by fhong             #+#    #+#             */
/*   Updated: 2018/12/29 05:57:06 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"ft_ls.h"
#define	D_TIME	dir_info->mod_time

static void		swap(t_dnode *a, t_dnode *b)
{
	char	*tmp_str;
	t_dir	*tmp_info;
	t_dnode	*tmp_child;

	tmp_str = b->dir_name;
	tmp_info = b->dir_info;
	tmp_child = b->child;
	b->dir_name = a->dir_name;
	b->dir_info = a->dir_info;
	b->child = a->child;
	a->dir_name = tmp_str;
	a->dir_info = tmp_info;
	a->child = tmp_child;
}

static t_dnode	*reverse_node(t_dnode *node)
{
	t_dnode *new;
	t_dnode *tmp;

	new = NULL;
	while (node)
	{
		tmp = node;
		node = node->next;
		tmp->next = new;
		new = tmp;
	}
	return (new);
}

static void		bubble_sort(t_dnode *node)
{
	t_dnode	*tmp;

	while (node)
	{
		tmp = node->next;
		while (tmp)
		{
			if (!t_FLAG && ft_strcmp(node->dir_name, tmp->dir_name) > 0)
				swap(node, tmp);
			else if (t_FLAG)
			{
				if (ft_strcmp(node->D_TIME, tmp->D_TIME) < 0)
					swap(node, tmp);
				else if (ft_strcmp(node->D_TIME, tmp->D_TIME) == 0 &&
						ft_strcmp(node->dir_name, tmp->dir_name) < 0)
					swap(node, tmp);
			}
			tmp = tmp->next;
		}
		node = node->next;
	}
}


t_dnode			*sort_node(t_dnode *node)
{
	bubble_sort(node);
	if (r_FLAG)
		node = reverse_node(node);
	return (node);
}
