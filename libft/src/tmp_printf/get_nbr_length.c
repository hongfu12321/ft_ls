/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:19:18 by fhong             #+#    #+#             */
/*   Updated: 2018/08/14 13:55:52 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

intmax_t	get_signed_nbr_length(va_list ap, t_arg *args)
{
	intmax_t	nbr;

	if (!(nbr = va_arg(ap, intmax_t)))
		return (0);
	if (LENGTH == 'h' && SPECIFIER != 'D')
		nbr = (short int)nbr;
	else if (LENGTH == 'l' || SPECIFIER == 'D')
		nbr = (long int)nbr;
	else if (LENGTH == 'H')
		nbr = (signed char)nbr;
	else if (LENGTH == 'L')
		nbr = (long long int)nbr;
	else if (LENGTH == 'j')
		nbr = (intmax_t)nbr;
	else if (LENGTH == 'z')
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t	get_unsigned_nbr_length(va_list ap, t_arg *args)
{
	uintmax_t	nbr;

	nbr = va_arg(ap, uintmax_t);
	if (LENGTH == 'h' && SPECIFIER != 'U' && SPECIFIER != 'O')
		nbr = (unsigned short)nbr;
	else if (LENGTH == 'l' || SPECIFIER == 'U' || SPECIFIER == 'O')
		nbr = (unsigned long int)nbr;
	else if (LENGTH == 'H')
		nbr = (unsigned char)nbr;
	else if (LENGTH == 'L')
		nbr = (unsigned long long int)nbr;
	else if (LENGTH == 'j')
		nbr = (uintmax_t)nbr;
	else if (LENGTH == 'z')
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
