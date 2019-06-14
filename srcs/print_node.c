/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:54 by fhong             #+#    #+#             */
/*   Updated: 2019/06/14 16:28:01 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static void	print_node_detail(char *color, t_dnode *node, t_p_info *p_info)
{
	if (!L_FLAG)
	{
		ft_printf(color);
		ft_printf("%-*s\033[0m", p_info->max_name + 1, node->dir_name);
	}
	else
	{
		if (S_FLAG)
			ft_printf("%*lld ", p_info->max_block_size,
					node->dir_info->st_blocks);
		ft_printf("%s", node->dir_info->permission);
		ft_printf("%*d ", p_info->max_lnk + 2, node->dir_info->lnk_nbr);
		ft_printf("%-*s ", p_info->max_uid + 1, node->dir_info->uid);
		ft_printf("%-*s ", p_info->max_gid + 1, node->dir_info->gid);
		ft_printf("%*lld ", p_info->max_size, node->dir_info->file_size);
		ft_printf("%s ", node->dir_info->mod_time);
		ft_printf(color);
		ft_printf("%s""\033[0m", node->dir_name);
		if (node->dir_info->link_path)
			ft_printf(" -> %s", node->dir_info->link_path);
		ft_printf("\n");
	}
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
		p_info->max_block_size = tmp;
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
		p_info->total_blocks_size += node->dir_info->st_blocks;
		node = node->next;
	}
}

void		handle_r_flag(t_dnode *begin)
{
	while (RR_FLAG && begin)
	{
		if (RR_FLAG && begin->child != NULL)
		{
			if (begin->dir_path)
				ft_printf("\n%s/", begin->dir_path);
			else
				ft_printf("\n");
			ft_printf("%s:\n", begin->dir_name);
			begin->child = print_node(begin->child);
		}
		begin = begin->next;
	}
}

t_dnode		*print_node(t_dnode *node)
{
	char		*color;
	t_p_info	*p_info;
	t_dnode		*begin;

	node = sort_node(node);
	begin = node;
	init(node, (p_info = (t_p_info *)malloc(sizeof(t_p_info))));
	(L_FLAG) && ft_printf("total %d\n", p_info->total_blocks_size);
	while (node)
	{
		color = get_color(node->dir_info->permission);
		if (!A_FLAG && node->dir_name[0] == '.')
		{
			node = node->next;
			continue;
		}
		print_node_detail(color, node, p_info);
		node = node->next;
	}
	free(p_info);
	(!L_FLAG) ? ft_printf("\n") : 0;
	(RR_FLAG && begin) ? handle_r_flag(begin) : 0;
	return (begin);
}
