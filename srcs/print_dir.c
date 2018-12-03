/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:54 by fhong             #+#    #+#             */
/*   Updated: 2018/12/02 21:34:43 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_dir_detail(t_dir *dir, int width)
{
	while (--width >= 0)
		write(1, " ", 1);
	ft_printf("%s  ", dir->permission);
	ft_printf("%2d ", dir->lnk_nbr);
	ft_printf("%s  ", dir->uid);
	ft_printf("%s  ", dir->gid);
	ft_printf("%-7lld", dir->file_size);
	ft_printf("%-s ", (dir->mod_time) + 4);
	ft_printf("\033[34m%s\033[0m\n", dir->dir_name);
}

void		print_dir(t_dir *dir, int width)
{
	while (dir)
	{
		print_dir_detail(dir, width);
		if (dir->child != NULL)
			print_dir(dir->child, width + 4);
		dir = dir->next;
	}
}
