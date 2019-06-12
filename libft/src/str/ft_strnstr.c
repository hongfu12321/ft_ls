/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:59:25 by fhong             #+#    #+#             */
/*   Updated: 2018/05/04 09:19:17 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	j = 0;
	while (big[j])
	{
		i = 0;
		while (big[j + i] == little[i] && j + i < len)
			if (!little[++i])
				return ((char *)(big + j));
		j++;
	}
	return (NULL);
}
