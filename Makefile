NAME = push_swap
SRC = main.c ops1.c ops2.c ops3.c solver.c solver_small.c parse.c 
SDIR = $(addprefix src/, $(SRC))
OBJ = $(SDIR:.c=.o)

CFLAGS  +=-Werror -Wextra -Wall
LIBFT	:= ./lib/libft
HEADERS	:= -I $(LIBFT)
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

.PHONY: all clean fclean re check

n:
	norminette -RCheckForbiddenSourceHeader -d ./src/*.c

debug: all
	gcc -g $(SDIR) $(LIBS) $(HEADERS) 
	lldb a.out 1 2 0

git_check:
	git clone https://github.com/gemartin99/Push_swap.git check

check: all
	@make
	@cp push_swap ./check/push_swap
	cd check ; bash push_swap_test.sh

viz: all
	@make
	@cp push_swap ./check/push_swap
	cd check ; python3 python_visualizer.py `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`

test: all
	./push_swap 8 0 -9 -1 -4 4 -2 -7 5 -5 -10 6 7 2 1 3 -3 -6 9 -8