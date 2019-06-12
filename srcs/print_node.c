/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:54 by fhong             #+#    #+#             */
/*   Updated: 2019/04/18 15:32:23 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static void	print_node_detail(t_dir *dir, t_p_info *p_info)
{
	if (s_FLAG)
		ft_printf("%*lld ", p_info->max_block_size, dir->st_blocks);
	ft_printf("%s", dir->permission);
	ft_printf("%*d", p_info->max_lnk + 2, dir->lnk_nbr);
	ft_printf("%*s", p_info->max_uid + 1, dir->uid);
	ft_printf("%*s", p_info->max_gid + 2, dir->gid);
	ft_printf("%*lld ", p_info->max_size + 2, dir->file_size);
	ft_printf("%s ", dir->mod_time);
}

static void	check_p_info(t_dnode *node, t_p_info *p_info)
{
	int tmp;

	if (!ft_strcmp(node->dir_name, ".") || !ft_strcmp(node->dir_name, ".."))
		return ;
	if ((tmp = ft_strlen(node->dir_name)) > p_info->max_name)
		p_info->max_name = tmp;
	if ((tmp = my_nbrlen(node->dir_info->lnk_nbr)) > p_info->max_lnk)
		p_info->max_lnk = tmp;
	if ((tmp = ft_strlen(node->dir_info->uid)) > p_info->max_uid)
		p_info->max_uid = tmp;
	if ((tmp = ft_strlen(node->dir_info->gid)) > p_info->max_gid)
		p_info->max_gid = tmp;
	if ((tmp = my_nbrlen(node->dir_info->file_size)) > p_info->max_size)
		p_info->max_size = tmp;
	if ((tmp = my_nbrlen(node->dir_info->st_blocks)) > p_info->max_block_size)
		p_info->max_block_size= tmp;
}

static void	init(t_dnode *node, t_p_info *p_info)
{
	p_info->max_name = 0;
	p_info->max_lnk = 0;
	p_info->max_uid = 0;
	p_info->max_gid = 0;
	p_info->max_size = 0;
	p_info->max_block_size = 0;
	p_info->total_blocks_size = 0;
	while (node)
	{
		check_p_info(node, p_info);
		if (ft_strcmp(".", node->dir_name) && ft_strcmp("..", node->dir_name))
			if ((a_FLAG) == (node->dir_name[0] == '.') || node->dir_name[0] != '.')
				p_info->total_blocks_size += node->dir_info->st_blocks;
		node = node->next;
	}
}

void	test_node(t_dnode *node)
{
	while (node)
	{
		ft_printf("name = %s\n", node->dir_name);
		node = node->next;
	}
}

void		handle_R_flag(t_dnode *begin)
{
	while (R_FLAG && begin)
	{
		if (R_FLAG && begin->child != NULL)
		{
			(begin->dir_path) ? ft_printf("\n%s/", begin->dir_path) : ft_printf("\n");
			ft_printf("%s:\n", begin->dir_name);
			print_node(begin->child, NULL);
		}
		begin = begin->next;
	}
}

void		print_node(t_dnode *node, char *path)
{
	t_p_info	*p_info;
	t_dnode		*begin;

	begin = node;
	p_info = (t_p_info *)malloc(sizeof(t_p_info));
	init(node, p_info);
	(l_FLAG) ? ft_printf("total %d\n", p_info->total_blocks_size) : 0;
	(R_FLAG && path) ? ft_printf("%s:\n", path) : 0;
	while (node)
	{
		if (!a_FLAG && node->dir_name[0] == '.')
		{
			node = node->next;
			continue;
		}
		(l_FLAG) ? print_node_detail(node->dir_info, p_info) : 0;
		ft_printf("%-*s", p_info->max_name + 1, node->dir_name);
		if (node->next)
			(l_FLAG) ? ft_printf("\n") : 0;
		node = node->next;
	}
	free(p_info);
	ft_printf("\n");
	(R_FLAG && begin) ? handle_R_flag(begin) : 0;
}
