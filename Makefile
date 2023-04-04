NAME = minitalk
OBJ  = client server
LIBFT	:= ./libft
HEADERS	:= -I $(LIBFT)
LIBS	:= $(LIBFT)/libft.a
CFLAGS +=-Werror -Wextra -Wall

all: $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME): libft $(OBJ)

$(OBJ): %: %.c
	$(CC) -o $@ $< $(CFLAGS) $(HEADERS) $(LIBS)

clean:
	make clean -C $(LIBFT)
	rm -f client server

fclean: clean

re: fclean all
	make fclean -C $(LIBFT)

#bonus: $(BNS_OBJ)
#	ar rc $(NAME) $(BNS_OBJ)

n:
	norminette -RCheckForbiddenSourceHeader

.PHONY: all clean fclean re $(NAME)