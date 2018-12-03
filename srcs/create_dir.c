/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:18:22 by fhong             #+#    #+#             */
/*   Updated: 2018/12/02 21:31:35 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	dir_uid_gid(t_dir *dir, STAT *statbuf)
{
	struct passwd	*my_info;
	struct group	*grp;

	my_info = getpwuid(statbuf->st_uid);
	grp = getgrgid(statbuf->st_gid);
	dir->uid = ft_strdup(my_info->pw_name);
	dir->gid = ft_strdup(grp->gr_name);
}

void	dir_permission(t_dir *dir, STAT *statbuf)
{
	char buf[10];

	dir->permission = (char *)malloc(sizeof(char) * 11);
	dir->permission[10] = '\0';
	buf[0] = S_ISDIR(statbuf->st_mode) ? 'd' : '-';
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

t_dir	*create_dir(char *dir_name, STAT statbuf)
{
	t_dir *dir;

	dir = (t_dir *)malloc(sizeof(t_dir));
	dir->dir_name = ft_strdup(dir_name);
	dir_permission(dir, &statbuf);
	dir->lnk_nbr = (int)statbuf.st_nlink;
	dir_uid_gid(dir, &statbuf);
	dir->file_size = (long long)statbuf.st_size;
	dir->mod_time = ctime(&statbuf.st_mtime);
	dir->mod_time[16] = '\0';
	dir->prev = NULL;
	dir->next = NULL;
	dir->child = NULL;
	return (dir);
}
