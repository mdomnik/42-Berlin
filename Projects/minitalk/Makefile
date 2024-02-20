# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 12:38:48 by mdomnik           #+#    #+#              #
#    Updated: 2024/02/20 17:20:24 by mdomnik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	=	client

SERVER	=	server

PRINTF	=	./libraries/ft_printf/libftprintf.a

LIBS	=	./libraries/Libft/libft.a

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra

SSRC	=	server.c\

CSRC	=	client.c\

OBJS	=	$(addprefix output/, $(SSRC:.c=.o), $(CSRC:.c=.o))

all:
	make -C ./libraries/Libft
	make -C ./libraries/ft_printf
	$(CC) $(CFLAGS) $(SSRC) $(LIBS) $(PRINTF) -o $(SERVER)
	$(CC) $(CFLAGS) $(CSRC) $(LIBS) $(PRINTF) -o $(CLIENT)

output/%.o: %.c | output
	$(CC) $(CFLAGS) -c $< -o $@

output:
	mkdir -p output

clean:
	make clean -C ./libraries/Libft
	make clean -C ./libraries/ft_printf
	rm -rf output

fclean:	clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re:		 fclean all

.PHONY: all clean fclean re