/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:11:24 by fhong             #+#    #+#             */
/*   Updated: 2018/12/02 21:41:53 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include "../libft/includes/libft.h"

# define R_FLAG		0
# define l_FLAG 	1
# define a_FLAG 	2
# define r_FLAG 	3
# define t_FLAG 	4

# define DIRENT		struct dirent
# define STAT		struct stat

typedef struct		s_dir
{
	char			*dir_name;
	char			*permission;
	int				lnk_nbr;
	char			*uid;
	char			*gid;
	long long		file_size;
	char			*mod_time;
	struct s_dir	*prev;
	struct s_dir	*next;
	struct s_dir	*child;
}					t_dir;

_Bool				g_flag[5];

/*
** create_dir.c
*/
t_dir				*create_dir(char *dir_name, STAT statbuf);

/*
** sort_dir.c
*/
t_dir				*sort_dir(t_dir *dir);

/*
** print_dir.c
*/
void				print_dir(t_dir *dir, int width);

/*
** utils.c
*/
void				test_print(t_dir *dir);
t_dir				*dir_add_last(t_dir *begin_dir, t_dir *new_dir);

#endif
