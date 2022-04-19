#
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Library making file.
#

SRC	=	sources/main.c \
		sources/sokoban.c \
		sources/manage_map.c \
		sources/key_action.c \
		sources/box_mouvement.c \
		sources/box_number.c \
		sources/game_status.c \
		sources/helping_message.c \
		sources/game_management.c \
		sources/key_entry.c


OBJ = 	$(SRC:.c=.o)

NAME = my_sokoban

LDFLAGS = -L./sources/lib/

LDLIBS = -lmy

CPPFLAGS = -I./includes -lncurses

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ) lib
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

lib:
	make -C sources/lib/

clean:
	make clean -C sources/lib/
	rm -f $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	make fclean -C sources/lib/
	rm -f $(NAME)

re: fclean all

cc: re clean

.PHONY: all clean fclean re cc lib
