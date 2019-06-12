/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:12:10 by fhong             #+#    #+#             */
/*   Updated: 2018/07/25 12:44:03 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen_base(intmax_t value, int base)
{
	int		len;

	len = 0;
	if (value == 0)
		return (1);
	if (value < 0 && base == 10)
		len++;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}
