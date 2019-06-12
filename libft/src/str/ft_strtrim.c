/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 09:37:24 by fhong             #+#    #+#             */
/*   Updated: 2018/05/03 21:15:00 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;

	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		s++;
	len = ft_strlen(s);
	while (ft_isspace(s[len - 1]) && len)
		len--;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_strncpy(str, (char *)s, len);
	str[len] = '\0';
	return (str);
}
