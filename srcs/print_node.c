/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:54 by fhong             #+#    #+#             */
/*   Updated: 2018/12/03 00:19:50 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_node_detail(t_dir *dir, char *dir_name, int width)
{
	while (--width >= 0)
		write(1, " ", 1);
	ft_printf("%s  ", dir->permission);
	ft_printf("%2d ", dir->lnk_nbr);
	ft_printf("%s  ", dir->uid);
	ft_printf("%s  ", dir->gid);
	ft_printf("%-7lld", dir->file_size);
	ft_printf("%-s ", (dir->mod_time) + 4);
	ft_printf("\033[34m%s\033[0m\n", dir_name);
}

void		print_node(t_dnode *node, int width)
{
	while (node)
	{
		print_node_detail(node->dir_info, node->dir_name, width);
		if (node->child != NULL)
			print_node(node->child, width + 4);
		node = node->next;
	}
}
