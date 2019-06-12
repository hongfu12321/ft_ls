/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uintmax_t_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 02:13:30 by fhong             #+#    #+#             */
/*   Updated: 2018/07/29 02:16:44 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_uintmax_t_base(uintmax_t value, char *base)
{
	uintmax_t base_len;

	base_len = ft_strlen(base);
	if (value >= base_len)
		ft_putnbr_base(value / base_len, base);
	write(1, &base[value % base_len], 1);
}
