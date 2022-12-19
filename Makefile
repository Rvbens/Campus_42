NAME = libftprintf.a
SRC = ft_printf.c ft_puts.c
OBJ = $(SRC:.c=.o)
#BNS_SRC = 
#OBJ_SRC = $(BNS_SRC:.c=.o)
CFLAGS +=-Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

#bonus: $(OBJ_SRC)
#	ar rc $(NAME) $(OBJ_SRC)

.PHONY: all clean fclean re

n:
	norminette -RCheckForbiddenSourceHeader

test:
	@cc $(CFLAGS) *.c 
	@./a.out
	@rm a.out