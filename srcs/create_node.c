/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:18:22 by fhong             #+#    #+#             */
/*   Updated: 2019/06/14 16:00:04 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	dir_uid_gid(t_dir *dir, STAT *statbuf)
{
	struct passwd	*my_info;
	struct group	*grp;

	my_info = getpwuid(statbuf->st_uid);
	grp = getgrgid(statbuf->st_gid);
	dir->uid = ft_strdup(my_info->pw_name);
	dir->gid = ft_strdup(grp->gr_name);
}

static void	dir_permission(t_dir *dir, STAT *statbuf)
{
	char buf[10];

	dir->permission = (char *)malloc(sizeof(char) * 11);
	dir->permission[10] = '\0';
	buf[0] = '-';
	if (S_ISDIR(statbuf->st_mode))
		buf[0] = 'd';
	else if (S_ISLNK(statbuf->st_mode))
		buf[0] = 'l';
	else if (S_ISCHR(statbuf->st_mode))
		buf[0] = 'c';
	else if (S_ISBLK(statbuf->st_mode))
		buf[0] = 'b';
	buf[1] = (statbuf->st_mode & S_IRUSR) ? 'r' : '-';
	buf[2] = (statbuf->st_mode & S_IWUSR) ? 'w' : '-';
	buf[3] = (statbuf->st_mode & S_IXUSR) ? 'x' : '-';
	buf[4] = (statbuf->st_mode & S_IRGRP) ? 'r' : '-';
	buf[5] = (statbuf->st_mode & S_IWGRP) ? 'w' : '-';
	buf[6] = (statbuf->st_mode & S_IXGRP) ? 'x' : '-';
	buf[7] = (statbuf->st_mode & S_IROTH) ? 'r' : '-';
	buf[8] = (statbuf->st_mode & S_IWOTH) ? 'w' : '-';
	buf[9] = (statbuf->st_mode & S_IXOTH) ? 'x' : '-';
	ft_strncpy(dir->permission, buf, 10);
}

static char	*dir_mod_time(STAT statbuf)
{
	char	*mod;
	char	*time;

	mod = ft_strnew(12);
	time = ctime(&statbuf.st_mtime);
	ft_strncpy(mod, &time[4], 12);
	if (strcmp(&time[19], " 2019") < 0)
		ft_strncpy(&mod[7], &time[19], 5);
	return (mod);
}

t_dnode		*create_node(char *dir_name, STAT statbuf, char *dir_path)
{
	char	buf[PATH_MAX + 1];
	t_dnode	*node;

	if (!A_FLAG && dir_name[0] == '.')
		return (NULL);
	node = (t_dnode *)malloc(sizeof(t_dnode));
	ft_bzero(node, sizeof(t_dnode));
	node->dir_name = ft_strdup(dir_name);
	node->dir_path = ft_strdup(dir_path);
	node->dir_info = (t_dir *)malloc(sizeof(t_dir));
	node->dir_info->lnk_nbr = (int)statbuf.st_nlink;
	node->dir_info->file_size = (long long)statbuf.st_size;
	node->dir_info->mod_time = dir_mod_time(statbuf);
	node->dir_info->mod_int = statbuf.st_mtime;
	node->dir_info->st_blocks = statbuf.st_blocks;
	dir_uid_gid(node->dir_info, &statbuf);
	dir_permission(node->dir_info, &statbuf);
	if (S_ISLNK(statbuf.st_mode))
	{
		realpath(dir_name, buf);
		node->dir_info->link_path = ft_strdup(buf);
	}
	else
		node->dir_info->link_path = NULL;
	return (node);
}
