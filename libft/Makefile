NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_isdigit.c  ft_memchr.c ft_split.c ft_putnbr_ptr.c ft_striteri.c ft_strncmp.c \
		ft_isascii.c ft_lstclear.c ft_lstsize.c ft_putnbr_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
		ft_toupper.c ft_calloc.c ft_itoa.c ft_lstlast.c ft_memcpy.c ft_putendl_fd.c ft_strlcat.c ft_strrchr.c \
		ft_isalpha.c ft_lstadd_front.c ft_lstnew.c ft_memset.c ft_putnbr.c ft_strcmp.c ft_strlen.c ft_substr.c \
		ft_bzero.c ft_isprint.c ft_lstiter.c ft_memcmp.c ft_putchar_fd.c ft_putstr_fd.c ft_strjoin.c ft_strnstr.c \
		ft_isalnum.c ft_lstadd_back.c ft_lstmap.c ft_memmove.c ft_putnbr_base.c ft_strchr.c ft_strlcpy.c ft_strtrim.c \
		ft_lstdelone.c ft_printf.c get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
