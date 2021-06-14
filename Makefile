# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 11:17:52 by rnoriko           #+#    #+#              #
#    Updated: 2021/06/14 11:36:03 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -c
CC = clang
HEADER = ft_printf.h

SRCS =	add_functions.c\
		add_prefix.c\
		convert_cdin.c\
		convert_uxpo.c\
		ft_printf.c\
		get_format_arg.c\
		make_unicode.c\
		print_right_left.c\
		print_zero.c

OBJS	= $(SRCS:.c=.o)

$(NAME):$(OBJS) $(HEADER)
	$(MAKE) all -C ./libft
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

bonus : all

clean :
	rm -f $(OBJS) $(OBJS_BONUS)
	$(MAKE) clean -C ./libft

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re : fclean all

.PHONY : all clean bonus fclean re