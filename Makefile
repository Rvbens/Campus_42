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
	git clone https://github.com/gemartin99/Push-Swap-Tester.git check

check: all
	@make
	@cp push_swap ./check/push_swap
	cd check ; bash push_swap_test.sh

viz: all
	@make
	@cp push_swap ./check/push_swap
	cd check ; python3 python_visualizer.py `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`

t1: all
	./push_swap 8 0 -9 -1 -4 4 -2 -7 5 -5 -10 6 7 2 1 3 -3 -6 9 -8 | wc -l

t2: all
	./push_swap 5

t3: all
	./push_swap "2 1"

t4: all
	./push_swap 1 2 3 4 5

t5: all
	./push_swap "-499 363 -114 492 -500 396 266 124 -206 479 -80 331 -55 268 -349 486 -182 -271 464 413 -417 -236 184 -211 401 -420 206 -389 -135 150 203 45 496 -160 -71 181 368 -316 -238 56 473 443 283 -487 -194 -497 5 26 78 297 -394 19 376 388 -287 162 169 236 -252 -488 -171 165 -474 397 -130 340 -483 -75 239 334 -232 68 -388 402 263 -368 313 151 41 328 330 282 -282 -254 374 -73 -34 -291 305 272 220 -157 -85 216 -78 -188 156 -111 338 144 -443 -471 119 -418 -372 259 76 245 494 -39 89 -479 -95 -264 478 -322 -449 -142 -399 222 -168 366 -345 196 428 379 -216 11111" | wc -l

t6:all
	./push_swap "3 a"

t: all
#	norminette -RCheckForbiddenSourceHeader
	@make t1
	@make t2
	@make t3
	@make t4
	@make t5
	@make t6