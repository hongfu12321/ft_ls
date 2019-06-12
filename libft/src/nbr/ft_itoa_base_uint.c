/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 23:31:23 by fhong             #+#    #+#             */
/*   Updated: 2018/07/26 23:38:41 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_uint(uintmax_t nb, char *base)
{
	uintmax_t	base_len;
	char		*result;
	int			i;

	i = 0;
	base_len = ft_strlen(base);
	if (base_len < 2 || 16 < base_len)
		return (NULL);
	result = ft_memalloc(sizeof(char) * 35);
	while (base_len <= nb)
	{
		result[i++] = base[nb % base_len];
		nb = nb / base_len;
	}
	if (base_len > nb)
		result[i++] = base[nb];
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}
