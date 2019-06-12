/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 09:54:45 by fhong             #+#    #+#             */
/*   Updated: 2018/05/03 19:08:35 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	register int	i;
	register char	*hptr;
	register char	*nptr;
	register int	n;

	hptr = (char *)haystack;
	nptr = (char *)needle;
	if (!(*nptr))
		return (hptr);
	n = ft_strlen(hptr) - ft_strlen(nptr) + 1;
	while (n-- > 0)
	{
		if (*hptr == *nptr)
		{
			i = -1;
			while (nptr[++i])
				if (hptr[i] != nptr[i])
					break ;
			if (nptr[i] == '\0')
				return (hptr);
		}
		hptr++;
	}
	return (NULL);
}
