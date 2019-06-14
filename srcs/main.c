/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:09:39 by fhong             #+#    #+#             */
/*   Updated: 2019/06/14 13:36:41 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_flag(char **av)
{
	int		i;
	int		j;
	char	*tmp;
	char 	flag[7] = "RlartsG";

	ft_memset(g_flag, 0, 7);
	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		j = 0;
		while (av[i][++j] && !ft_isspace(av[i][j]))
		{
			if ((tmp = ft_strchr(flag, av[i][j])))
				g_flag[tmp - flag] = 1;
			else
				ft_exit("Usage: ft_ls[RlartsG][file name]\n");
		}
		i++;
	}
	return (i);
}

t_dnode	*get_node(char *dir_name, char *dir_path)
{
	DIR		*dp;
	char	*tmp_name;
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
		tmp = create_node(info->d_name, statbuf, dir_path);
		if (S_ISDIR(statbuf.st_mode) && R_FLAG)
		{
			if (ft_strcmp(tmp->dir_name, ".") != 0 &&
					ft_strcmp(tmp->dir_name, "..") != 0)
			{
				tmp->child = get_node(info->d_name, (tmp_name = get_dir_path(tmp->dir_path, tmp->dir_name)));
				ft_strdel(&tmp_name);
			}
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
	t_dnode	*node;

	i = (ac > 1) ? check_flag(av) : 1;
	if (i == ac)
	{
		node = get_node(".", ".");
		node = print_node(node);
		free_node(node);
	}
	while (i < ac)
	{
		node = get_node(av[i], av[i]);
		if (node)
		{
			node = print_node(node);
			free_node(node);
		}
		else
			ft_printf("ls: %s: No such file or directory\n", av[i]);
		i++;
	}
	return (0);
}
