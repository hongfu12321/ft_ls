/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 23:00:59 by fhong             #+#    #+#             */
/*   Updated: 2018/10/19 17:07:20 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft.h"

# define RESET			"\033[0m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN    		"\033[36m"
# define WHITE   		"\033[37m"
# define BOLDBLACK		"\033[1m\033[30m"
# define BOLDRED		"\033[1m\033[31m"
# define BOLDGREEN		"\033[1m\033[32m"
# define BOLDYELLOW		"\033[1m\033[33m"
# define BOLDBLUE		"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define BOLDCYAN		"\033[1m\033[36m"
# define BOLDWHITE		"\033[1m\033[37m"

# define HASH			args->hash
# define MINUS			args->minus
# define PLUS			args->plus
# define SPACE			args->space
# define ZERO			args->zero
# define FLAG			HASH + MINUS + PLUS + SPACE + ZERO
# define NEGATIVE		args->negative
# define WIDTH			args->width
# define PRECISION		args->precision
# define LENGTH			args->length
# define SPECIFIER		args->specifier
# define TRUE(x, y)	x > y ? x - y : 0

typedef struct		s_arg
{
	int				hash;
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				width;
	int				precision;
	char			length;
	int				negative;
	char			specifier;
}					t_arg;

typedef size_t		(*t_func)(va_list va, t_arg *arg);

/*
**	main.c
*/

size_t				get_args(va_list ap, char **format);
size_t				print_format(va_list args, char *format, size_t char_size);
size_t				ft_printf(const char *format, ...);

/*
** tools.c
*/

void				initial_args(t_arg *args);
void				print_args(t_arg *args);
void				free_args(t_arg *args);
void				reset_flag(t_arg *args);

/*
** is_function.c
*/

int					is_specifier(char c);
int					is_length(char c);
int					is_character(char c);

/*
** get_args.c
*/

void				handle_flag(char **format, t_arg *args);
void				handle_width(char **format, t_arg *args, va_list ap);
void				handle_precision(char **format, t_arg *args, va_list ap);
void				handle_length(char **format, t_arg *args);

/*
** get_handle_finc.c
*/

size_t				handle_specifier(char **format, t_arg *args, va_list ap);

/*
** get_nbr_length.c
*/

intmax_t			get_signed_nbr_length(va_list ap, t_arg *args);
uintmax_t			get_unsigned_nbr_length(va_list ap, t_arg *args);

/*
** handle
*/

size_t				handle_str(va_list ap, t_arg *args);
size_t				handle_wstr(va_list ap, t_arg *args);
size_t				handle_char(va_list ap, t_arg *args);
size_t				handle_wchar(va_list ap, t_arg *args);
size_t				handle_int(va_list ap, t_arg *args);
size_t				handle_unsigned(va_list ap, t_arg *args);
size_t				handle_escape(va_list ap, t_arg *args);
size_t				handle_octal(va_list ap, t_arg *args);
size_t				handle_hex(va_list ap, t_arg *args);
size_t				handle_ptr(va_list ap, t_arg *args);

#endif
