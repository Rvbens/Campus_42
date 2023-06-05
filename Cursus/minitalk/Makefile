NAME = minitalk
OBJ  = client server
OBJ_BNS  = client_bonus server_bonus
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

$(OBJ_BNS): %: %.c
	$(CC) -o $@ $< $(CFLAGS) $(HEADERS) $(LIBS)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean

re: fclean all
	make fclean -C $(LIBFT)

bonus: $(OBJ_BNS)

n:
	norminette -RCheckForbiddenSourceHeader

.PHONY: all clean fclean re bonus $(NAME) libft