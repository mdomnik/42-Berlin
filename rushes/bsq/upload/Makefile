FLAGS = -Wall -Wextra -Werror
NAME = bsq
SRC_NAME = main.c
SRC_FLIES = ft_files.c
SRC_MDA = ft_mda.c
SRC_BOX_LOGIC = ft_box_logic.c

main: $(SRC_NAME) $(SRC_FLIES) $(SRC_MDA) $(SRC_BOX_LOGIC)
	cc $(FLAGS) $(SRC_NAME) $(SRC_FLIES) $(SRC_MDA) $(SRC_BOX_LOGIC) -o $(NAME)

clean: $(NAME)
	rm $(NAME)

fclean: $(NAME)
	rm $(NAME)
