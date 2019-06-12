/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_t_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:57:17 by fhong             #+#    #+#             */
/*   Updated: 2018/07/29 01:23:58 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	*ft_size_t_new(size_t size)
{
	size_t	*str;
	int		i;

	i = 0;
	if (!(str = (size_t *)malloc(sizeof(size_t) * (size + 1))))
		return (NULL);
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
