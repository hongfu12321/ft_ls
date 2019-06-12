/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:01:30 by fhong             #+#    #+#             */
/*   Updated: 2018/08/14 13:56:54 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	handle_char(va_list ap, t_arg *args)
{
	char	c;

	if (LENGTH == 'l')
		return (handle_wchar(ap, args));
	if (is_specifier(SPECIFIER))
		c = va_arg(ap, int);
	else
		c = SPECIFIER;
	if (!MINUS && WIDTH != -1)
	{
		if (ZERO)
			ft_put_char_times('0', WIDTH - 1);
		else
			ft_put_char_times(' ', WIDTH - 1);
	}
	ft_putchar(c);
	if (MINUS && WIDTH != -1)
		ft_put_char_times(' ', WIDTH - 1);
	if (WIDTH > 0)
		return (WIDTH);
	return (1);
}
