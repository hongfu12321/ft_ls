/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:19:52 by fhong             #+#    #+#             */
/*   Updated: 2018/12/02 21:40:54 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*dir_add_last(t_dir *begin_dir, t_dir *new_dir)
{
	t_dir *tmp;

	if (begin_dir == NULL)
		return (new_dir);
	tmp = begin_dir;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_dir;
	new_dir->prev = tmp;
	return (begin_dir);
}

void	test_print(t_dir *dir)
{
	while (dir)
	{
		ft_printf("%s\n", dir->dir_name);
		dir = dir->next;
	}
}
