/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:30:24 by fhong             #+#    #+#             */
/*   Updated: 2018/05/03 08:32:11 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	register char			*d;
	register const char		*s;
	register char			ch;
	register size_t			i;

	d = (char *)dst;
	s = (const char *)src;
	ch = (char)c;
	i = n;
	while (i--)
		if ((*d++ = *s++) == ch)
			return (d);
	return (NULL);
}
