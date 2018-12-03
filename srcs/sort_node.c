/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:14:21 by fhong             #+#    #+#             */
/*   Updated: 2018/12/03 01:03:14 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"ft_ls.h"
#define	D_TIME	dir_info->mod_time

static void	swap(t_dnode *a, t_dnode *b)
{
	char	*tmp_str;
	t_dir	*tmp_info;

	tmp_str = b->dir_name;
	tmp_info = b->dir_info;
	b->dir_name = a->dir_name;
	b->dir_info = a->dir_info;
	a->dir_name = tmp_str;
	a->dir_info = tmp_info;
}
/*
static void		reverse_dir(t_dir *dir)
{
	(void)dir;	
}*/

static void	bubble_sort(t_dnode *node)
{
	t_dnode	*tmp;

	while (node)
	{
		if (node->child != NULL)
			bubble_sort(node->child);
		tmp = node->next;
		while (tmp)
		{
			if (!g_flag[t_FLAG] && ft_strcmp(node->dir_name, tmp->dir_name) > 0)
				swap(node, tmp);
			else if (g_flag[t_FLAG] && ft_strcmp(node->D_TIME, tmp->D_TIME) > 0)
				swap(node, tmp);
			tmp = tmp->next;
		}
		node = node->next;
	}
}


t_dnode		*sort_node(t_dnode *node)
{
	bubble_sort(node);
	return (node);
}
