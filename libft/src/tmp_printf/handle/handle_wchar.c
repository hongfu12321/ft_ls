/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:55:36 by fhong             #+#    #+#             */
/*   Updated: 2018/08/14 13:59:09 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	handle_wchar(va_list ap, t_arg *args)
{
	wchar_t	wc;

	wc = va_arg(ap, wchar_t);
	if (!MINUS && WIDTH > 0)
	{
		if (ZERO)
			ft_put_char_times('0', WIDTH - 1);
		else
			ft_put_char_times(' ', WIDTH - 1);
	}
	ft_putwchar(wc);
	if (MINUS && WIDTH > 0)
		ft_put_char_times(' ', WIDTH - 1);
	if (WIDTH > 0)
		return ((size_t)WIDTH);
	return (1);
}
