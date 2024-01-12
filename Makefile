NAME = pipex

CC = cc 
FLAGS = -g -Wall -Wextra -Werror

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

val:
	@read -p "Enter cmd: " cmd; \
	read -p "Enter cmd2: " cmd2; \
	valgrind --leak-check=full --track-origins=yes --trace-children=yes \
	./pipex "file1.txt" "$${cmd}" "$${cmd2}" "file2.txt"

.PHONY: all clean fclean re
