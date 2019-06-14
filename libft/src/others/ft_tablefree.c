/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablefree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 10:20:47 by fuhong            #+#    #+#             */
/*   Updated: 2018/10/18 10:23:22 by fuhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tablefree(char **table)
{
	int i;

	i = -1;
	while (table[++i])
		ft_strdel(&table[i]);
	free(table);
}