/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:19:52 by fhong             #+#    #+#             */
/*   Updated: 2019/06/14 16:39:15 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dnode	*node_add_last(t_dnode *begin_node, t_dnode *new_node)
{
	t_dnode *tmp;

	if (begin_node == NULL)
		return (new_node);
	tmp = begin_node;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (begin_node);
}

void	test_print(t_dnode *node)
{
	while (node)
	{
		ft_printf("%s, %p\n", node->dir_name, node);
		if (node->child)
			test_print(node->child);
		node = node->next;
	}
}

int		my_nbrlen(long long size)
{
	int len;

	len = 0;
	while (size > 0)
	{
		size /= 10;
		++len;
	}
	return (len);
}

char	*get_color(char *permission)
{
	if (!G_FLAG)
		return ("\033[0m");
	if (permission[9] == 't' && permission[8] == 'w')
		return ("\033[32;7m");
	if (permission[0] == 'd')
		return ("\033[1;36m");
	if (permission[0] == 'c')
		return ("\033[42m");
	if (permission[0] == 'b')
		return ("\033[45m");
	if (permission[0] == 'l')
		return ("\033[35m");
	if (permission[3] == 'x')
		return ("\033[31m");
	return ("\033[0m");
}

char	*get_dir_path(char *str1, char *str2)
{
	int		str1_len;
	int		str2_len;
	int		len;
	char	*dir_path;

	if (!str1)
		return (ft_strdup(str2));
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	len = str1_len + str2_len + 1;
	dir_path = (char *)malloc(sizeof(char) * (len + 1));
	dir_path[len] = '\0';
	ft_strncpy(dir_path, str1, str1_len);
	dir_path[str1_len] = '/';
	ft_strncpy(&dir_path[str1_len + 1], str2, str2_len);
	return (dir_path);
}
