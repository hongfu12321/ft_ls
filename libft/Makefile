# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/02 10:18:57 by fhong             #+#    #+#              #
#    Updated: 2019/05/28 23:18:05 by fhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

CC			:=	gcc
CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -I includes

IS			:=	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_islower ft_isspace		\
				ft_isoperator ft_isprime ft_isupper

LST			:=	ft_lstadd ft_lstadd_last ft_lstdel ft_lstdelone ft_lstiter ft_lstmap	\
				ft_lstnew ft_putlst

MEM			:=	ft_bzero ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_swap	\
				ft_memdel ft_memmove ft_memset

NBR			:=	ft_atoi ft_intlen_base ft_intnew ft_size_t_new ft_uintlen_base ft_itoa 	\
				ft_itoa_base ft_itoa_base_uint ft_atoi_intmax

PUT			:=	ft_put_base_unsigned ft_put_char_times ft_putchar ft_putchar_fd			\
				ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_base ft_putnbr_fd			\
				ft_putnbr_uintmax_t ft_putnbr_uintmax_t_base ft_putnstr ft_putstr		\
				ft_putstr_fd

STR			:=	ft_strcat ft_strcmp ft_strdup ft_striteri ft_strlen ft_strncat			\
				ft_strnequ ft_strnstr ft_strsplit ft_strtrim ft_wstrlen ft_strchr		\
				ft_strcpy ft_strequ ft_strjoin ft_strmap ft_strncmp ft_strnew			\
				ft_strrchr ft_strstr ft_tolower ft_strclr ft_strdel ft_striter			\
				ft_strlcat ft_strmapi ft_strncpy ft_strnlen ft_strrev ft_strsub			\
				ft_toupper

OTHER		:=	ft_exit ft_tablefree

GNL			:=	get_next_line

FT_PRINTF	:=	buffer diuoxb_setup ft_printf_c ft_printf_p set_flags dispatch			\
				ft_printf ft_printf_diuoxb ft_printf_s

T_FT_PRINTF	:=	ft_printf get_args get_handle_func get_nbr_length is_function tools		\
				handle/handle_char handle/handle_escape handle/handle_wstr				\
				handle/handle_int handle/handle_ptr handle/handle_hex handle/handle_str	\
				handle/handle_unsigned handle/handle_wchar handle/handle_octal

FILES		:=	$(addprefix is/, $(IS))					\
				$(addprefix lst/, $(LST))				\
				$(addprefix mem/, $(MEM))				\
				$(addprefix nbr/, $(NBR))				\
				$(addprefix put/, $(PUT))				\
				$(addprefix str/, $(STR))				\
				$(addprefix others/, $(OTHER))			\
				$(addprefix gnl/, $(GNL))				\
				$(addprefix ft_printf/, $(FT_PRINTF))

SRC			:=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ			:=	$(SRC:.c=.o)


.PHONY = all clean fclean re

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[32mCompiled Library\033[0m"

clean:
	@rm -f $(OBJ)
	@rm -f *.DS_Store

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mRemoved Library\033[0m"

re: fclean all
