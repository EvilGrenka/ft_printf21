# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 13:35:32 by rnoriko           #+#    #+#              #
#    Updated: 2021/06/04 19:33:55 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC				=	libft.h

SRCS			=	ft_strdup.c  ft_strlen.c\
					ft_calloc.c  ft_memset.c \
					ft_strjoin.c ft_itoa.c \
					ft_putchar_fd.c ft_putstr_fd.c \
					ft_isdigit.c ft_strncmp.c

OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -c

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS) $(INC)
				$(CC) $(CFLAGS) $(SRCS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
