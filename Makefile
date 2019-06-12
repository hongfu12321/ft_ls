# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjacques <mjacques@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 11:32:00 by mjacques          #+#    #+#              #
#    Updated: 2019/04/10 16:41:46 by fhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
RM			= rm -rf
NAME		= ft_ls
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= libft/libft.a
INCLUDES	= -I includes/\
			  -I libft/header

BASE		= main.c create_node.c sort_node.c print_node.c utils_node.c\
			  free_node.c
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
