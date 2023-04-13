NAME = fractol
SRC = main.c fractal.c parse.c hooks.c draw.c
OBJ = $(SRC:.c=.o)
#BNS_SRC = 
#OBJ_SRC = $(BNS_SRC:.c=.o)

CFLAGS  +=-Werror -Wextra -Wall
LIBFT	:= ./lib/libft
LIBMLX	:= ./lib/MLX42
HEADERS	:= -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a -lglfw -lm -L"/Users/rchaves-/.brew/opt/glfw/lib/"



all:  $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(HEADERS) $(CFLAGS)
	
$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C $(LIBMLX)
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

test1:
	@make
	./fractol mandelbrot

test2:
	@make
	./fractol julia -0.1755 0.69734

test3:
	@make
	./fractol batman