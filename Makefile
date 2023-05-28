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

.PHONY: all clean fclean re

n:
	norminette -RCheckForbiddenSourceHeader -d *.c

ch1:
	./checkers/checker_OS

t0: all
	./push_swap 1 2 3 -1 6 8 9 0

t1: all
	# Wrong character error
	./push_swap 1 2 a

t2: all
	#Duplicates error
	./push_swap 1 2 6 2

t3: all
	./push_swap 2 3 1

debug: all
	gcc -g $(SRC) $(LIBS) $(HEADERS) 
	lldb a.out 1 2 0

