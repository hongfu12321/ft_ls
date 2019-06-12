/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:40:21 by fhong             #+#    #+#             */
/*   Updated: 2018/07/24 22:44:24 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr(wchar_t *wstr, size_t n)
{
	if (!wstr)
		return ;
	if (ft_wstrlen(wstr) >= n)
		write(1, wstr, n);
	else
		return ;
}
