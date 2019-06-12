/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 17:16:06 by fhong             #+#    #+#             */
/*   Updated: 2018/08/14 13:57:08 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	handle_escape(va_list ap, t_arg *args)
{
	(void)ap;
	if (!MINUS)
	{
		if (!ZERO)
			ft_put_char_times(' ', WIDTH - 1);
		else
			ft_put_char_times('0', WIDTH - 1);
	}
	ft_putchar('%');
	if (MINUS)
		ft_put_char_times(' ', WIDTH - 1);
	if (WIDTH > 0)
		return (WIDTH);
	return (1);
}
