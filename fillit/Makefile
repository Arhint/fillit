NAME =		fillit

FLG =		-Wall -Wextra -Werror

SRC = 		board.c \
			coordinates.c \
			main.c \
			solver.c \
			valid.c \
			tools.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ./libft/
	gcc $(FLG) $(OBJ) -L ./libft/ -lft -o $(NAME)

%.o: %.c $(HEADER)
	gcc -c $(FLG) -o $@ $<

clean:
	make -C ./libft clean
	/bin/rm -f *.o

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all