NAME = client server
SRC = client.c server.c
OBJ = $(SRC:.c=.o)
#BNS_SRC = 
#BNS_OBJ = $(BNS_SRC:.c=.o)
CFLAGS +=-Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BNS_OBJ)
	ar rc $(NAME) $(BNS_OBJ)

.PHONY: all clean fclean re