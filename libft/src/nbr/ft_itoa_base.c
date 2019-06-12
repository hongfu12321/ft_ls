/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 21:04:10 by fhong             #+#    #+#             */
/*   Updated: 2018/08/01 16:05:35 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(intmax_t value, char *base)
{
	char	*str;
	int		size;
	int		length;
	int		flag;

	flag = 0;
	size = 0;
	length = ft_strlen(base);
	if (length < 2 || length > 16)
		return (0);
	size = ft_intlen_base(value, length) + flag;
	str = ft_strnew(size);
	if (value < 0 && length == 10)
	{
		str[0] = '-';
		value = -value;
	}
	while (size > flag)
	{
		str[size - 1] = base[value % length];
		size--;
		value /= length;
	}
	return (str);
}
