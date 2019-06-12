/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 12:50:38 by fhong             #+#    #+#             */
/*   Updated: 2018/07/30 13:06:43 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uintlen_base(uintmax_t value, int base)
{
	int		len;

	len = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}
