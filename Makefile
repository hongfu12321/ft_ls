# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 11:32:00 by mjacques          #+#    #+#              #
#    Updated: 2018/12/02 21:29:40 by fhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
RM			= rm -rf
NAME		= ft_ls
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
LIBFT		= libft/libft.a
INCLUDES	= -I includes/\
			  -I libft/header

BASE		= main.c create_dir.c sort_dir.c print_dir.c utils_dir.c
FUNCTIONS	= $(BASE)

FILES		= $(addprefix srcs/, $(FUNCTIONS))
OBJECTS		= $(FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
	@echo "\033[32mft_ls compiled!\033[0m"

$(LIBFT):
	@make -C libft/

clean:
	@$(RM) $(OBJECTS)
	@make clean -C libft/

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft/
	@echo "\033[31mft_ls cleaned!\033[0m"

re: fclean all
