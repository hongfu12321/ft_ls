/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:11:24 by fhong             #+#    #+#             */
/*   Updated: 2019/06/14 14:40:42 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <limits.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include "../libft/includes/libft.h"

# define RR_FLAG	g_flag[0]
# define L_FLAG 	g_flag[1]
# define A_FLAG 	g_flag[2]
# define R_FLAG 	g_flag[3]
# define T_FLAG 	g_flag[4]
# define S_FLAG 	g_flag[5]
# define G_FLAG		g_flag[6]

# define DIRENT		struct dirent
# define STAT		struct stat

typedef struct		s_dir
{
	char			*permission;
	int				lnk_nbr;
	char			*uid;
	char			*gid;
	long long		file_size;
	blkcnt_t		st_blocks;
	char			*mod_time;
	long			mod_int;
	char			*link_path;
}					t_dir;

typedef struct		s_dnode
{
	char			*dir_name;
	char			*dir_path;
	t_dir			*dir_info;
	struct s_dnode	*next;
	struct s_dnode	*child;
}					t_dnode;

typedef struct		s_p_info
{
	int				max_name;
	int				max_lnk;
	int				max_uid;
	int				max_gid;
	int				max_size;
	int				max_block_size;
	blkcnt_t		total_blocks_size;
}					t_p_info;

_Bool				g_flag[7];

/*
** main.c
*/
t_dnode				*get_node(char *dir_name, char *dir_path);
t_dnode				*get_node_helper(t_dnode *tmp);

/*
** create_dir.c
*/
t_dnode				*create_node(char *dir_name, STAT statbuf, char *dir_path);

/*
** sort_dir.c
*/
t_dnode				*sort_node(t_dnode *node);

/*
** print_dir.c
*/
t_dnode				*print_node(t_dnode *node);
void				test_node(t_dnode *node);

/*
** free_dir.c
*/
void				free_node(t_dnode *node);

/*
** utils.c
*/
int					my_nbrlen(long long size);
void				test_print(t_dnode *node);
char				*get_dir_path(char *str1, char *str2);
char				*get_color(char *permission);
t_dnode				*node_add_last(t_dnode *begin_node, t_dnode *new_node);

#endif

#ifndef st_mtime
# define ST_MTIME	st_mtimespec.tv_sec
#endif
