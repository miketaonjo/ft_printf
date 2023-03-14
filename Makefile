# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 14:04:36 by mcloarec          #+#    #+#              #
#    Updated: 2023/03/14 00:30:05 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_printf.c
SRCS += srcs/ft_printunsigned.c
SRCS += srcs/ft_printchar.c
SRCS += srcs/ft_printnbr.c
SRCS += srcs/ft_printpercent.c
SRCS += srcs/ft_printstr.c
SRCS += srcs/ft_printhexa.c
SRCS += srcs/ft_printptr.c
SRCS += srcs/ft_strdup.c
SRCS += srcs/ft_calloc.c
SRCS += srcs/ft_memset.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
		gcc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
