/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:31:14 by fhong             #+#    #+#             */
/*   Updated: 2018/05/02 14:31:34 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	register char		*d;
	register const char	*s;
	register size_t		i;

	d = (char *)dst;
	s = (const char *)src;
	i = len;
	if (s < d)
		while (i--)
			d[i] = s[i];
	else
		while (i--)
			*d++ = *s++;
	return (dst);
}
