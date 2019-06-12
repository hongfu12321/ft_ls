/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:43:55 by fhong             #+#    #+#             */
/*   Updated: 2018/08/14 13:57:42 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	int_print(t_arg *args, intmax_t nbr, size_t nbr_len, size_t precision)
{
	size_t	length;
	size_t	width;

	width = (WIDTH == -1) ? 0 : (size_t)WIDTH;
	length = (SPACE == 1 || PLUS == 1 || NEGATIVE) ? 1 : 0;
	if (!MINUS && (!ZERO || PRECISION != -1))
		ft_put_char_times(' ', TRUE(width, (length + precision)));
	if (length == 1)
	{
		if (NEGATIVE && nbr != 0)
			write(1, "-", 1);
		else if (!NEGATIVE)
			PLUS == 1 ? write(1, "+", 1) : write(1, " ", 1);
	}
	if (MINUS == 0 && ZERO != 0 && PRECISION == -1)
		ft_put_char_times('0', TRUE(width, (length + precision)));
	ft_put_char_times('0', TRUE((size_t)precision, nbr_len));
	if (nbr != 0 || length == 1)
		NEGATIVE == 0 ? ft_putnbr_uintmax_t(nbr) : ft_putnbr_uintmax_t(-nbr);
	if (MINUS == 1)
		ft_put_char_times(' ', TRUE(width, (length + precision)));
	return (width > precision + length ? width : length + precision);
}

size_t	handle_int(va_list ap, t_arg *args)
{
	intmax_t	nbr;
	size_t		precision;
	size_t		nbr_len;

	nbr = get_signed_nbr_length(ap, args);
	precision = (PRECISION != -1) ? (size_t)PRECISION : 0;
	if (nbr == 0 && precision == 0 && PRECISION != -1)
		nbr_len = 0;
	if (nbr < 0)
		NEGATIVE = 1;
	if (nbr == 0 && PRECISION == -1 && WIDTH == -1 && FLAG == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	nbr_len = (nbr != 0) ? ft_intlen_base(nbr, 10) - NEGATIVE : 1;
	if (nbr == 0 && PRECISION != -1)
		nbr_len = 0;
	if (precision < nbr_len)
		return (int_print(args, nbr, nbr_len, nbr_len));
	return (int_print(args, nbr, nbr_len, precision));
}
