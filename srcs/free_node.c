/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 03:22:26 by fhong             #+#    #+#             */
/*   Updated: 2018/12/08 21:36:48 by fuhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	free_dir(t_dir *dir)
{
	ft_strdel(&dir->permission);
	ft_strdel(&dir->uid);
	ft_strdel(&dir->gid);
	ft_strdel(&dir->mod_time);
	free(dir);
}

void		free_node(t_dnode *node)
{
	t_dnode	*tmp;

	while (node)
	{
		tmp = node;
		ft_strdel(&node->dir_name);
		free_dir(node->dir_info);
		if (node->child != NULL)
			free_node(node->child);
		node = node->next;
		free(tmp);
	}
}
