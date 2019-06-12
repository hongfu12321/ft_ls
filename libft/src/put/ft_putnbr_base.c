/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:20:04 by fhong             #+#    #+#             */
/*   Updated: 2018/07/30 13:18:00 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(intmax_t value, char *base)
{
	int base_len;

	base_len = ft_strlen(base);
	if (value < 0)
	{
		write(1, "-", 1);
		value *= (-1);
	}
	if (value >= base_len)
		ft_putnbr_base(value / base_len, base);
	write(1, &base[value % base_len], 1);
}
