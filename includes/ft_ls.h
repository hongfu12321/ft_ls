/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:11:24 by fhong             #+#    #+#             */
/*   Updated: 2018/12/04 03:32:02 by fhong            ###   ########.fr       */
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
	char			*permission;
	int				lnk_nbr;
	char			*uid;
	char			*gid;
	long long		file_size;
	char			*mod_time;
}					t_dir;

typedef struct		s_dnode
{
	char			*dir_name;
	t_dir			*dir_info;
	struct s_dnode	*next;
	struct s_dnode	*child;
}					t_dnode;

_Bool				g_flag[5];

/*
** create_dir.c
*/
t_dnode				*create_node(char *dir_name, STAT statbuf);

/*
** sort_dir.c
*/
t_dnode				*sort_node(t_dnode *node);

/*
** print_dir.c
*/
void				print_node(t_dnode *node);

/*
** free_dir.c
*/
void				free_node(t_dnode *node);

/*
** utils.c
*/
void				test_print(t_dnode *node);
t_dnode				*node_add_last(t_dnode *begin_node, t_dnode *new_node);

#endif

#ifndef st_mtime
# define st_mtime	st_mtimespec.tv_sec
#endif
