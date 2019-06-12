/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:29:59 by fhong             #+#    #+#             */
/*   Updated: 2018/07/13 11:01:36 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_last(t_list *alst, t_list *new)
{
	t_list	*tmp;

	if (!alst)
		write(1, "FUCK!\n", 6);
	tmp = alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
