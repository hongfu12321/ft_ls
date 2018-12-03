/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:14:21 by fhong             #+#    #+#             */
/*   Updated: 2018/12/02 22:35:29 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		swap(t_dir *d1, t_dir *d2)
{
	t_dir *d1_prev;
	t_dir *d1_next;
	t_dir *d2_prev;
	t_dir *d2_next;
	t_dir *tmp;

	tmp = d2;
	d1_prev = d1->prev;
	d1_next = (d1->next != d2) ? d1->next : d1;
	d2_prev = (d1->next != d2) ? d2->prev : d2;
	d2_next = d2->next;

	d1_prev->next = d2;
	d2->prev = d1_prev;
	d2->next = d1->next;
	d1->prev = d2->prev;
	d1->next = d2_next;
}
/*
static void		reverse_dir(t_dir *dir)
{
	(void)dir;	
}*/

static t_dir	*bubble_sort(t_dir *dir, _Bool t_flag)
{
	t_dir	*begin;
	t_dir	*tmp;
	t_dir	*tmp1;
	t_dir	*prev;
	t_dir	*next;

	begin = dir;
	tmp = dir;
	while (tmp->next)
	{
		ft_putstr("IN\n");
		ft_printf("111, %s, %d\n", tmp->dir_name, t_flag);
		prev = tmp->prev;
		tmp1 = tmp->next;
		while (tmp1)
		{
			ft_printf("222, %s\n", tmp1->dir_name);
			next = tmp1->next;
		/*	if (t_flag && ft_strcmp(tmp->mod_time, tmp1->mod_time) > 0)
			{
				ft_printf("in time sort\n");
				(prev) ? swap(tmp, tmp1) : (begin = tmp1);
			}
			else if(!t_flag && ft_strcmp(tmp->dir_name, tmp1->dir_name) > 0)
			{
				ft_printf("in name sort\n");
				(prev) ? swap(tmp, tmp1) : (begin = tmp1);
			}*/
			ft_printf("cmp: %s, %s\n", tmp->dir_name, tmp1->dir_name);
			if(ft_strcmp(tmp->dir_name, tmp1->dir_name) > 0)
				(prev) ? swap(tmp, tmp1) : (begin = tmp1);
			tmp1 = next;
			sleep(1);
		}
		if (prev)
			ft_printf("prev = %s, next = %s\n", prev->dir_name, prev->next->next->dir_name);
		tmp = (prev) ? prev->next->next : begin->next;
	ft_putstr("in name sort\n");
	}
	return (begin);
}


t_dir			*sort_dir(t_dir *dir)
{
	t_dir	*begin;

	begin = bubble_sort(dir, g_flag[t_FLAG]);
	return (begin);
}
