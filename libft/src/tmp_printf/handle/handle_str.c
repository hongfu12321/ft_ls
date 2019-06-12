/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:34:08 by fhong             #+#    #+#             */
/*   Updated: 2018/08/14 13:58:32 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	handle_str_width(t_arg *args, char *str, size_t str_len)
{
	size_t width;

	if (!*str)
		str_len = 0;
	width = (WIDTH == -1) ? 0 : (size_t)WIDTH;
	if (width > str_len)
	{
		if (!MINUS)
		{
			if (ZERO == 0)
				ft_put_char_times(' ', TRUE(width, str_len));
			else
				ft_put_char_times(' ', TRUE(width, str_len));
		}
		ft_putnstr(str, str_len);
		if (MINUS)
			ft_put_char_times(' ', TRUE(width, str_len));
		str_len = width;
	}
	else
		ft_putnstr(str, str_len);
	return (str_len);
}

size_t	handle_str(va_list ap, t_arg *args)
{
	char	*str;
	size_t	str_len;

	if (LENGTH == 'l')
		return (handle_wstr(ap, args));
	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	str_len = ft_strlen(str);
	if (PRECISION != -1)
		return (handle_str_width(args, str, PRECISION));
	return (handle_str_width(args, str, str_len));
}
