# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 12:24:07 by mdomnik           #+#    #+#              #
#    Updated: 2024/01/20 19:22:33 by mdomnik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Imlx -g 

MLXFLAGS=	-L ./libraries/mlx -lmlx -lXext -lX11

LIBS	=	./libraries/Libft/libft.a

PRINTF  =  ./libraries/ft_printf/ft_printf.a

SRCS	=	main.c exitandfree.c spritehandle.c processmap.c utils.c inputs.c conditions.c \
			validatemap.c validatemap2.c errors.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			make -C ./libraries/mlx
			make -C ./libraries/Libft
			make -C ./libraries/ft_printf
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) $(PRINTF) -o $(NAME)

clean:
			make clean -C ./libraries/mlx
			make clean -C ./libraries/Libft
			make clean -C ./libraries/ft_printf
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
