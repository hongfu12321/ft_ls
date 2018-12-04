/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:54 by fhong             #+#    #+#             */
/*   Updated: 2018/12/04 03:20:26 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_node_detail(t_dir *dir, char *dir_name)
{
	ft_printf("%s:\n", dir_name);
	ft_printf("%s  ", dir->permission);
	ft_printf("%2d ", dir->lnk_nbr);
	ft_printf("%s  ", dir->uid);
	ft_printf("%s ", dir->gid);
	ft_printf("%6lld ", dir->file_size);
	ft_printf("%s ", dir->mod_time);
}

void		print_node(t_dnode *node)
{
	(g_flag[R_FLAG]) ? ft_printf("%s:\n", "DIR_NAME") : 0;
	while (node)
	{
		if (!g_flag[a_FLAG])
			while (node->dir_name[0] == '.')
				node = node->next;
		(g_flag[l_FLAG]) ? print_node_detail(node->dir_info, node->dir_name) : 0;
		//ft_printf("\033[34m%s\033[0m", node->dir_name);
		ft_printf("%s\t", node->dir_name);
		(g_flag[a_FLAG]) && write(1, "\n", 1);
		(!node->next) ? write(1, "\n", 1) : 0;
		if (g_flag[R_FLAG] && node->child != NULL)
			print_node(node->child);
		node = node->next;
	}
}
