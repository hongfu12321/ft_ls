/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:54 by fhong             #+#    #+#             */
/*   Updated: 2019/04/10 16:41:11 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

static void	print_node_detail(t_dir *dir, t_p_info *p_info)
{
	printf("%s", dir->permission);
	printf("%*d", p_info->max_lnk + 2, dir->lnk_nbr);
	printf("%*s", p_info->max_uid + 1, dir->uid);
	printf("%*s", p_info->max_gid + 2, dir->gid);
	printf("%*lld ", p_info->max_size + 2, dir->file_size);
	printf("%s ", dir->mod_time);
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
}

static void	init(t_dnode *node, t_p_info *p_info)
{
	p_info->max_name = 0;
	p_info->max_lnk = 0;
	p_info->max_uid = 0;
	p_info->max_gid = 0;
	p_info->max_size = 0;
	while (node)
	{
		check_p_info(node, p_info);
		node = node->next;
	}
}

void	test_node(t_dnode *node)
{
	while (node)
	{
		printf("name = %s\n", node->dir_name);
		node = node->next;
	}
}

void		print_node(t_dnode *node)
{
	t_p_info	*p_info;
	t_dnode		*begin;

	node = sort_node(node);
	begin = node;
	p_info = (t_p_info *)malloc(sizeof(t_p_info));
	(l_FLAG) ? ft_printf("total %3d\n", 0) : 0;
	init(node, p_info);
	while (node)
	{
		if (!a_FLAG && node->dir_name[0] == '.')
		{
			node = node->next;
			continue;
		}
		(l_FLAG) ? print_node_detail(node->dir_info, p_info) : 0;
		//ft_printf("\033[34m%s\033[0m", node->dir_name);
		printf("%-*s", p_info->max_name + 1, node->dir_name);
		if (node->next)
			(l_FLAG) ? printf("\n") : 0;
		node = node->next;

	}
	free(p_info);
	printf("\n");
	while (R_FLAG && begin)
	{
		if (R_FLAG && begin->child != NULL)
		{
			printf("\n%s:\n", begin->dir_name);
			print_node(begin->child);
		}
		begin = begin->next;
	}
}
