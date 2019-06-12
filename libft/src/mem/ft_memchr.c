/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:02:49 by fhong             #+#    #+#             */
/*   Updated: 2018/05/03 08:29:53 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	register unsigned char ch;
	register unsigned char *ptr;

	ch = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n--)
		if (*ptr++ == ch)
			return ((void *)--ptr);
	return (0);
}
