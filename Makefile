# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 14:04:36 by mcloarec          #+#    #+#              #
#    Updated: 2022/04/25 18:38:11 by mcloarec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c
SRCS += ft_printunsigned.c
SRCS += ft_printchar.c
SRCS += ft_printnbr.c
SRCS += ft_printpercent.c
SRCS += ft_printstr.c
SRCS += ft_printhexa.c
SRCS += ft_printptr.c
SRCS += ft_strdup.c
SRCS += ft_calloc.c
SRCS += ft_memset.c

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
