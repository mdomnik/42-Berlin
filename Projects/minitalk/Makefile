# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 12:38:48 by mdomnik           #+#    #+#              #
#    Updated: 2024/02/24 20:03:47 by mdomnik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT  =   client
SERVER  =   server
PRINTF  =   ./libraries/ft_printf/libftprintf.a
LIBS    =   ./libraries/Libft/libft.a
CC      =   cc
CFLAGS  =   -Wall -Werror -Wextra
SSRC    =   server.c
CSRC    =   client.c
SOBJS   =   $(addprefix output/, $(SSRC:.c=.o))
COBJS   =   $(addprefix output/, $(CSRC:.c=.o))

all: $(SERVER) $(CLIENT)

$(SERVER): $(SOBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) $(PRINTF) -o $@

$(CLIENT): $(COBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) $(PRINTF) -o $@

output/%.o: %.c | output
	$(CC) $(CFLAGS) -c $< -o $@

output:
	mkdir -p output

clean:
	make clean -C ./libraries/Libft
	make clean -C ./libraries/ft_printf
	rm -rf output

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re: fclean all

.PHONY: all clean fclean re