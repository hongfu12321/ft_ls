/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 22:24:59 by fhong             #+#    #+#             */
/*   Updated: 2018/08/14 13:59:22 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	handle_wstr_width(t_arg *args, wchar_t *wstr, size_t str_len)
{
	size_t width;

	width = (WIDTH == -1) ? 0 : (size_t)WIDTH;
	if (!*wstr)
		str_len = 0;
	if (width > str_len)
	{
		if (!MINUS)
			ft_put_char_times(' ', TRUE(width, str_len));
		ft_putnwstr(wstr, str_len);
		if (MINUS)
			ft_put_char_times(' ', TRUE(width, str_len));
		str_len = width;
	}
	else
		ft_putnwstr(wstr, str_len);
	return (str_len);
}

size_t	handle_wstr(va_list ap, t_arg *args)
{
	wchar_t	*wstr;
	size_t	str_len;

	wstr = va_arg(ap, wchar_t *);
	str_len = ft_wstrlen(wstr);
	if (PRECISION != -1)
		return (handle_wstr_width(args, wstr, PRECISION));
	return (handle_wstr_width(args, wstr, str_len));
}
