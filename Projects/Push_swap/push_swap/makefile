# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 13:19:09 by mdomnik           #+#    #+#              #
#    Updated: 2024/02/03 20:47:33 by mdomnik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

LIBS	=	./libraries/Libft/libft.a

PRINTF  =  ./libraries/ft_printf/ft_printf.a

SRCS	=	push_swap.c list_prep.c check.c utils.c operations_1.c operations_2.c operations_3.c sort_arg_1.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			make -C ./libraries/Libft
			make -C ./libraries/ft_printf
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(PRINTF) -o $(NAME)

clean:
			make clean -C ./libraries/Libft
			make clean -C ./libraries/ft_printf
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re