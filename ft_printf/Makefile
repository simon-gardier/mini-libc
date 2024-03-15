CC=gcc
CFLAGS+=-Wextra -Werror -Wall
SRC = 	ft_printf.c \
		conversion.c \
		conversion_1.c \
		utils.c
OBJ_FOLDER=./obj/
OBJ = $(SRC:.c=.o)
OBJ_PATH = $(addprefix $(OBJ_FOLDER), $(OBJ))
HEADER=ft_printf.h

EXEC= libftprintf.a

$(EXEC): $(OBJ_PATH)
	ar rcs $(EXEC) $(OBJ_PATH)

$(OBJ_FOLDER)%.o: %.c $(HEADER)
	mkdir -p $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(EXEC)

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -f $(EXEC)

re: fclean all
