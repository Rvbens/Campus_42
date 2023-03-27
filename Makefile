NAME = fractol
SRC = main.c fractal.c parse.c
OBJ = $(SRC:.c=.o)
#BNS_SRC = 
#OBJ_SRC = $(BNS_SRC:.c=.o)

CFLAGS  +=-Werror -Wextra -Wall
LIBFT	:= ./lib/libft
LIBMLX	:= ./lib/MLX42
HEADERS	:= -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libfj.a -lglfw -lm -L"/Users/rchaves-/.brew/opt/glfw/lib/"



all:  $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(HEADERS) $(CFLAGS)
	
$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(HEADERS) 

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ) $(OBJ_SRC)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

#bonus: $(OBJ_SRC)
#	ar rc $(NAME) $(OBJ_SRC)

.PHONY: all clean fclean re

n:
	norminette -RCheckForbiddenSourceHeader

test:
	make
	./fractol julia