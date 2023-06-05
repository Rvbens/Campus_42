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

t0: all
	./push_swap
	./push_swap ""

t1: all
	./push_swap 8 0 -9 -1 -4 4 -2 -7 5 -5 -10 6 7 2 1 3 -3 -6 9 -8

t2: all
	./push_swap 5

t3: all
	./push_swap "2 1"

t4: all
	./push_swap 1 2 3 4 5

t5: all
	./push_swap "-499 363 -114 492 -500 396 266 124 -206 479 -80 331 -55 268 -349 486 -182 -271 464 413 -417 -236 184 -211 401 -420 206 -389 -135 150 203 45 496 -160 -71 181 368 -316 -238 56 473 443 283 -487 -194 -497 5 26 78 297 -394 19 376 388 -287 162 169 236 -252 -488 -171 165 -474 397 -130 340 -483 -75 239 334 -232 68 -388 402 263 -368 313 151 41 328 330 282 -282 -254 374 -73 -34 -291 305 272 220 -157 -85 216 -78 -188 156 -111 338 144 -443 -471 119 -418 -372 259 76 245 494 -39 89 -479 -95 -264 478 -322 -449 -142 -399 222 -168 366 -345 196 428 379 -216 11111" | wc -l

t6: all
	./push_swap `ruby -e "puts (-66..66).to_a.shuffle.join(' ')"`

t7: all
	./push_swap 35 -6 50 54 -38 16 -45 -18 59 -27 -21 -2 -19 34 32 -58 -28 41 -35 17 21 52 14 -23 45 55 40 -56 -61 48 64 62 61 63 -12 15 43 -54 -60 24 28 -44 -48 37 33 -66 -64 49 -8 -14 -20 -53 -30 44 60 -62 20 13 0 23 11 -10 4 -43 -5 -1 29 -11 -22 66 8 53 65 25 6 47 19 -15 -40 -39 -57 3 31 -41 -29 -4 -49 -31 36 30 10 -25 -26 -55 2 -51 9 56 -24 -65 18 -42 51 -46 -47 -34 26 -37 -33 5 1 -32 -63 39 46 42 12 -16 -50 -9 -7 22 -59 38 27 -36 58 7 57 -13 -52 -17 -3

t8: all
	./push_swap "35 -6 50 54 -38 16 -45 -18 59 -27 -21 -2 -19 34 32 -58 -28 41 -35 17 21 52 14 -23 45 55 40 -56 -61 48 64 62 61 63 -12 15 43 -54 -60 24 28 -44 -48 37 33 -66 -64 49 -8 -14 -20 -53 -30 44 60 -62 20 13 0 23 11 -10 4 -43 -5 -1 29 -11 -22 66 8 53 65 25 6 47 19 -15 -40 -39 -57 3 31 -41 -29 -4 -49 -31 36 30 10 -25 -26 -55 2 -51 9 56 -24 -65 18 -42 51 -46 -47 -34 26 -37 -33 5 1 -32 -63 39 46 42 12 -16 -50 -9 -7 22 -59 38 27 -36 58 7 57 -13 -52 -17 -3"

t: all
#	norminette -RCheckForbiddenSourceHeader
	@make t1
	@make t2
	@make t3
	@make t4
	@make t5

# EVALUATION TEST
# Error management
ev_er1:all
	./push_swap 42 a

ev_er2:all
	./push_swap 1 2 3 4 4

ev_er3:all
	./push_swap 1 2147483648

ev_er4:all
	./push_swap

# Push_swap - Identity test
ev1:all
	./push_swap 42

ev2:all
	./push_swap 2 3

ev3:all
	./push_swap 0 1 2 3

ev4:all
	./push_swap 0 1 2 3 4 5 6 7 8 9

ev5:all
	./push_swap 1 4 7 9

ev_sorted:
	@make ev1
	@make ev2
	@make ev3
	@make ev4
	@make ev5

# Push_swap - Simple version
ev6:all
	ARG="2 1 0"; ./push_swap $$ARG | ./checker_OS $$ARG

ev7:all
	ARG="2 4 -7"; ./push_swap $$ARG | ./checker_OS $$ARG

ev_simple:
	@make ev6
	@make ev7

# Another simple version
ev8:all
	ARG="1 5 2 4 3"; ./push_swap $$ARG | ./checker_OS $$ARG
	ARG="1 5 2 4 3"; ./push_swap $$ARG | wc -l

ev9:all
	ARG="5 4 3 7 9"; ./push_swap $$ARG | ./checker_OS $$ARG
	ARG="5 4 3 7 9"; ./push_swap $$ARG | wc -l

# Push_swap - Middle version
ev10:all
	ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker_OS $$ARG; ./push_swap $$ARG | wc -l

# Push_swap - Advanced version
ev11:all
	ARG=`ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker_OS $$ARG; ./push_swap $$ARG | wc -l