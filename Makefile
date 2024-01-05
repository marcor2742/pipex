NAME = pipex

CC = cc 
FLAGS = -Wall -Wextra -Werror

SRC = pipex.c 

OBJ = $(SRC:.c=.o)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@


all: $(NAME)


LIBFT = ./libft/libft.a

$(NAME): $(OBJ)
	make all -C libft
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
	make re -C libft

.PHONY: all clean fclean re
