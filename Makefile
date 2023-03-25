NAME = fractol
SRC = main.c fractal.c
OBJ = $(SRC:.c=.o)
#BNS_SRC = 
#OBJ_SRC = $(BNS_SRC:.c=.o)

CFLAGS +=-Werror -Wextra -Wall
LIBMLX	:= ./lib/MLX42
HEADERS	:= -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -lm -L"/Users/rchaves-/.brew/opt/glfw/lib/"



all: $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(HEADERS) $(CFLAGS)
	
$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(HEADERS) 

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
	make
	./fractol