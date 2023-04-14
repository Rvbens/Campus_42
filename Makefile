NAME = fractol
SRC = main.c fractal.c parse.c hooks.c draw.c
OBJ = $(SRC:.c=.o)
BNS_DIR = ./bonus/
BNS_LST = main_bonus.c fractal_bonus.c parse_bonus.c hooks_bonus.c draw_bonus.c
BNS_SRC = $(addprefix $(BNS_DIR), $(BNS_LST))
BNS_OBJ = $(BNS_SRC:.c=.o)

CFLAGS  +=-Werror -Wextra -Wall
LIBFT	:= ./lib/libft
LIBMLX	:= ./lib/MLX42
HEADERS	:= -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a -lglfw -lm -L"/Users/rchaves-/.brew/opt/glfw/lib/"



all:  $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(HEADERS) $(CFLAGS)
	
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@make -C $(LIBMLX)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(HEADERS) 

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

bonus: $(BNS_OBJ)
	@make -C $(LIBFT)
	@make -C $(LIBMLX)
	$(CC) -o $(NAME) $(BNS_OBJ) $(LIBS) $(HEADERS) 

.PHONY: all clean fclean re

n:
	norminette -RCheckForbiddenSourceHeader -d *.c

test1:
	@make
	./fractol mandelbrot

test2:
	@make
	./fractol julia -0.1755 0.69734

test3:
	@make
	./fractol batman