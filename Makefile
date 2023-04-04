NAME = minitalk
CFLAGS +=-Werror -Wextra -Wall

all: $(NAME)

$(NAME): 
	@make cl
	@make sv

cl: client.c
	gcc client.c -o client $(CFLAGS)
	
sv:	server.c
	gcc server.c -o server $(CFLAGS)

clean:
	rm -f client server

fclean: clean

re: fclean all

#bonus: $(BNS_OBJ)
#	ar rc $(NAME) $(BNS_OBJ)

n:
	norminette -RCheckForbiddenSourceHeader

.PHONY: all clean fclean re client server