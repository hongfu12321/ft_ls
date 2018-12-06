/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:18:22 by fhong             #+#    #+#             */
/*   Updated: 2018/12/06 18:32:44 by fuhong           ###   ########.fr       */
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
	if (S_ISDIR(statbuf->st_mode))
		buf[0] = S_ISDIR(statbuf->st_mode) ? 'd' : '-';
	else
		buf[0] = S_ISLNK(statbuf->st_mode) ? 'l' : '-';
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
	char 	*mod;
	char	*time;

	mod = ft_strnew(12);
	time = ctime(&statbuf.st_mtime);
	ft_strncpy(mod, &time[4], 12);
	return (mod);
}

t_dnode		*create_node(char *dir_name, STAT statbuf)
{
	t_dnode	*node;
	
	node = (t_dnode *)malloc(sizeof(t_dnode));
	node->dir_name = ft_strdup(dir_name);
	node->next = NULL;
	node->child = NULL;
	node->dir_info = (t_dir *)malloc(sizeof(t_dir));
	node->dir_info->lnk_nbr = (int)statbuf.st_nlink;
	node->dir_info->file_size = (long long)statbuf.st_size;
	node->dir_info->mod_time = dir_mod_time(statbuf);
	dir_uid_gid(node->dir_info, &statbuf);
	dir_permission(node->dir_info, &statbuf);
	return (node);
}
