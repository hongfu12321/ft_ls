/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:14:21 by fhong             #+#    #+#             */
/*   Updated: 2019/06/14 12:27:55 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"ft_ls.h"
#define	D_TIME	dir_info->mod_time

static void		swap(t_dnode *a, t_dnode *b)
{
	char	*tmp_name;
	char	*tmp_path;
	t_dir	*tmp_info;
	t_dnode	*tmp_child;

	tmp_name = b->dir_name;
	tmp_path = b->dir_path;
	tmp_info = b->dir_info;
	tmp_child = b->child;
	b->dir_name = a->dir_name;
	b->dir_path = a->dir_path;
	b->dir_info = a->dir_info;
	b->child = a->child;
	a->dir_name = tmp_name;
	a->dir_path = tmp_path;
	a->dir_info = tmp_info;
	a->child = tmp_child;
}

static t_dnode	*reverse_node(t_dnode *node)
{
	t_dnode *tmp;

	if (node == NULL || node->next == NULL)
		return (node);
	tmp = reverse_node(node->next);
	node->next->next = node;
	node->next = NULL;
	return (tmp);
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
				if (node->dir_info->mod_int < tmp->dir_info->mod_int)
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
