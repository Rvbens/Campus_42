NAME = minitalk
SRC = client.c server.c
OBJ = $(SRC:.c=.o)
CFLAGS +=-Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	gcc client.c -o client $(CFLAGS)
	gcc server.c -o server $(CFLAGS)

clean:
	rm -f client server

fclean: clean

re: fclean all

#bonus: $(BNS_OBJ)
#	ar rc $(NAME) $(BNS_OBJ)

n:
	norminette -RCheckForbiddenSourceHeader

.PHONY: all clean fclean re