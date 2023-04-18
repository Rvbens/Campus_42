NAME = push_swap
SRC = main.c ops1.c ops2.c ops3.c solver.c parse.c
OBJ = $(SRC:.c=.o)

CFLAGS  +=-Werror -Wextra -Wall
LIBFT	:= ./lib/libft
HEADERS	:= -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBFT)/libft.a

all:  $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(HEADERS) $(CFLAGS)
	
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@make bonus -C $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(HEADERS) 

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

n:
	norminette -RCheckForbiddenSourceHeader -d *.c

t:
	@make
	@make t0

t0:
	./push_swap 1 2 3 -1 6 8

t1:
	# Wrong character error
	./push_swap 1 2 a

t2:
	#Duplicates error
	./push_swap 1 2 6 2

