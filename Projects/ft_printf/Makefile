# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 21:00:40 by mdomnik           #+#    #+#              #
#    Updated: 2024/01/31 01:18:15 by mdomnik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printstr.c ft_printdigit.c ft_printchar.c
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
