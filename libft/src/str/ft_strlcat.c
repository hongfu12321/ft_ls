/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:11:34 by fhong             #+#    #+#             */
/*   Updated: 2018/05/03 11:11:55 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	register size_t nd;
	register size_t ns;

	nd = ft_strlen(dst);
	ns = ft_strlen(src);
	if (dstsize > nd)
	{
		dstsize = dstsize > nd + ns ? nd + ns + 1 : dstsize;
		dst[--dstsize] = '\0';
		while (dstsize-- > nd)
			dst[dstsize] = src[dstsize - nd];
		dstsize++;
	}
	return (dstsize + ns);
}
