/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:09:39 by fhong             #+#    #+#             */
/*   Updated: 2018/12/06 12:02:13 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_flag(char **av)
{
	int		i;
	int		j;
	char	*tmp;
	char 	flag[5] = "Rlart";

	ft_memset(g_flag, 0, 5);
	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		j = 0;
		while (av[i][++j] && !ft_isspace(av[i][j]))
		{
			if ((tmp = ft_strchr(flag, av[i][j])))
				g_flag[tmp - flag] = 1;
			else
				ft_error("Usage: ft_ls[Rlart][file name]\n");
		}
		i++;
	}
	return (i);
}

t_dnode	*get_node(char *dir_name)
{
	DIR		*dp;
	t_dnode	*node;
	t_dnode	*tmp;
	DIRENT	*info;
	STAT	statbuf;

	node = NULL;
	tmp = NULL;
	if ((dp = opendir(dir_name)) == NULL)
		return (NULL);
	chdir(dir_name);
	while ((info = readdir(dp)) != NULL)
	{
		lstat(info->d_name, &statbuf);
		tmp = create_node(info->d_name, statbuf);
		if (S_ISDIR(statbuf.st_mode))
		{
			if (ft_strcmp(tmp->dir_name, ".") != 0 &&
					ft_strcmp(tmp->dir_name, "..") != 0)
				tmp->child = get_node(info->d_name);
		}
		node = node_add_last(node, tmp);
	}
	chdir("..");
	closedir(dp);
	return (node);
}

int		main(int ac, char **av)
{
	int		i;
	int		check;
	t_dnode	*node;

	i = (ac > 1) ? check_flag(av) : 1;
	check = 0;
	if (i == ac)
		check = 1;
	while (check == 1 || (i < ac && (node = get_node(av[i]))))
	{
		if (check == 1)
		{
			node = get_node(".");
			check = 0;
		}
		sort_node(node);
		print_node(node);
		free_node(node);
		i++;
	}
//	while (1)
//		;
	return (0);
}
