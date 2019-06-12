/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:47:04 by fhong             #+#    #+#             */
/*   Updated: 2018/08/14 13:55:15 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		varified_flag(char flag, t_arg *args)
{
	if (flag == '#')
		HASH = 2;
	else if (flag == '-')
		MINUS = 1;
	else if (flag == '+')
		PLUS = 1;
	else if (flag == ' ')
		SPACE = 1;
	else if (flag == '0')
		ZERO = 1;
	if (flag == '#' || flag == '-' || flag == '+' || flag == ' ' || flag == '0')
		return (1);
	return (0);
}

void	handle_flag(char **format, t_arg *args)
{
	while (varified_flag(**format, args))
		(*format)++;
}

void	handle_width(char **format, t_arg *args, va_list ap)
{
	if (**format == '*')
	{
		WIDTH = va_arg(ap, size_t);
		(*format)++;
	}
	else
	{
		WIDTH = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	handle_precision(char **format, t_arg *args, va_list ap)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			PRECISION = va_arg(ap, size_t);
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			PRECISION = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
			PRECISION = 0;
	}
}

void	handle_length(char **format, t_arg *args)
{
	if (**format == 'h' || **format == 'l' || **format == 'j' ||
			**format == 'z' || **format == 't' || **format == 'L')
	{
		LENGTH = **format;
		(*format)++;
	}
	if (LENGTH == 'l' && **format == 'l')
	{
		LENGTH = 'L';
		(*format)++;
	}
	else if (LENGTH == 'h' && **format == 'h')
	{
		LENGTH = 'H';
		(*format)++;
	}
}
