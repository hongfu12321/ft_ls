/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:26:30 by fhong             #+#    #+#             */
/*   Updated: 2018/08/14 13:58:48 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	uint_print(t_arg *args, uintmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t width;

	width = (WIDTH == -1) ? 0 : (size_t)WIDTH;
	if (MINUS == 0 && (ZERO == 0 || PRECISION != -1))
		ft_put_char_times(' ', TRUE(width, precision));
	if (MINUS == 0 && ZERO != 0 && PRECISION == -1)
		ft_put_char_times('0', TRUE(width, precision));
	ft_put_char_times('0', TRUE(precision, nbr_len));
	if (nbr != 0)
		ft_putnbr_uintmax_t(nbr);
	if (MINUS == 1)
		ft_put_char_times(' ', TRUE(width, precision));
	return (width > precision ? width : precision);
}

size_t	handle_unsigned(va_list ap, t_arg *args)
{
	uintmax_t	nbr;
	size_t		precision;
	size_t		nbr_len;

	nbr = get_unsigned_nbr_length(ap, args);
	precision = (PRECISION != -1) ? (size_t)PRECISION : 0;
	if (nbr == 0 && precision == 0 && PRECISION != -1)
		nbr_len = 0;
	if (nbr == 0 && PRECISION == -1 && WIDTH == -1 && FLAG == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	nbr_len = (nbr != 0) ? ft_uintlen_base(nbr, 10) : 1;
	if (nbr == 0 && PRECISION != -1)
		nbr_len = 0;
	if (precision < nbr_len)
		return (uint_print(args, nbr, nbr_len, nbr_len));
	return (uint_print(args, nbr, nbr_len, precision));
}
