/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:54 by fhong             #+#    #+#             */
/*   Updated: 2018/12/06 12:10:39 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_node_detail(t_dir *dir)
{
	ft_printf("%s  ", dir->permission);
	ft_printf("%2d ", dir->lnk_nbr);
	ft_printf("%s  ", dir->uid);
	ft_printf("%s ", dir->gid);
	ft_printf("%6lld ", dir->file_size);
	ft_printf("%s ", dir->mod_time);
}

void		print_node(t_dnode *node)
{
	(R_FLAG) ? ft_printf("%s:\n", "DIR_NAME") : 0;
	(l_FLAG) ? ft_printf("total %3d\n", 0) : 0;
	while (node)
	{
		(R_FLAG) ? ft_printf("%s:\n", node->dir_name) : 0;
		if (!a_FLAG && node->dir_name[0] == '.')
		{
			node = node->next;
			continue;
		}
		(l_FLAG) ? print_node_detail(node->dir_info) : 0;
		//ft_printf("\033[34m%s\033[0m", node->dir_name);
		ft_printf("%s", node->dir_name);
		if (node->next)
			(l_FLAG) ? write(1, "\n", 1) : write(1, "   ", 3);
		if (R_FLAG && node->child != NULL)
			print_node(node->child);
		node = node->next;
	}
	write(1, "\n", 1);
}
