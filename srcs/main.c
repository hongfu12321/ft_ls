/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:09:39 by fhong             #+#    #+#             */
/*   Updated: 2018/12/02 21:42:50 by fhong            ###   ########.fr       */
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

t_dir	*get_dir(char *dir_name)
{
	DIR		*dp;
	t_dir	*dir;
	t_dir	*tmp;
	DIRENT	*info;
	STAT	statbuf;

	dir = NULL;
	tmp = NULL;
	if ((dp = opendir(dir_name)) == NULL)
		return (NULL);
	chdir(dir_name);
	while ((info = readdir(dp)) != NULL)
	{
		lstat(info->d_name, &statbuf);
		tmp = create_dir(info->d_name, statbuf);
		if (S_ISDIR(statbuf.st_mode))
		{
			if (ft_strcmp(tmp->dir_name, ".") != 0 &&
					ft_strcmp(tmp->dir_name, "..") != 0)
				tmp->child = get_dir(info->d_name);
		}
		dir = dir_add_last(dir, tmp);
	}
	chdir("..");
	closedir(dp);
	return (dir);
}

int		main(int ac, char **av)
{
	int		i;
	t_dir	*dir;

	i = (ac > 1) ? check_flag(&av[1]) : 1;
	if (i == ac)
	{
		dir = get_dir(".");
		print_dir(dir, 0);
	}
	while (av[i] && (dir = get_dir(av[i])))
	{
		test_print(dir);
		ft_printf("--------------------\n");
		dir = sort_dir(dir);
		ft_printf("--------------------\n");
		test_print(dir);
//		free_dir(dir);
		i++;
	}

	return (0);
}
