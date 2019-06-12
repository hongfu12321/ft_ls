/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:10:05 by fhong             #+#    #+#             */
/*   Updated: 2018/08/14 13:56:26 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	initial_args(t_arg *args)
{
	HASH = 0;
	MINUS = 0;
	PLUS = 0;
	SPACE = 0;
	ZERO = 0;
	NEGATIVE = 0;
	WIDTH = -1;
	PRECISION = -1;
	LENGTH = '\0';
	SPECIFIER = '\0';
}

void	print_args(t_arg *args)
{
	ft_printf("negative = %d\n", NEGATIVE);
	ft_printf("hash = %d\n", HASH);
	ft_printf("minus = %d\n", MINUS);
	ft_printf("plus = %d\n", PLUS);
	ft_printf("space = %d\n", SPACE);
	ft_printf("zero = %d\n", ZERO);
	ft_printf("width = %d\n", WIDTH);
	ft_printf("precision = %d\n", PRECISION);
	ft_printf("length = %c\n", LENGTH);
	ft_printf("specifier = %c\n", SPECIFIER);
}
