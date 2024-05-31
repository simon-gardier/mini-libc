CC=gcc
CFLAGS=-Wextra -Werror -Wall

SRC = 	./conversion/ft_atoi.c \
		./memory/ft_bzero.c \
		./memory/ft_calloc.c \
		./string/ft_isalnum.c \
		./string/ft_isalpha.c \
		./string/ft_isascii.c \
		./string/ft_isdigit.c \
		./string/ft_isprint.c \
		./conversion/ft_itoa.c \
		./memory/ft_memchr.c \
		./memory/ft_memcmp.c \
		./memory/ft_memcpy.c \
		./memory/ft_memmove.c \
		./memory/ft_memset.c \
		./miscellaneous/ft_putchar_fd.c \
		./miscellaneous/ft_putendl_fd.c \
		./miscellaneous/ft_putnbr_fd.c \
		./miscellaneous/ft_putstr_fd.c \
		./string/ft_split.c \
		./string/ft_strchr.c \
		./string/ft_strdup.c \
		./string/ft_striteri.c \
		./string/ft_strjoin.c \
		./string/ft_strlcat.c \
		./string/ft_strlcpy.c \
		./string/ft_strlen.c \
		./string/ft_strmapi.c \
		./string/ft_strncmp.c \
		./string/ft_strnstr.c \
		./string/ft_strrchr.c \
		./string/ft_strtrim.c \
		./string/ft_substr.c \
		./string/ft_tolower.c \
		./string/ft_toupper.c \
		./miscellaneous/ft_printf.c \
		./miscellaneous/ft_printf_1.c \
		./miscellaneous/ft_get_next_line.c

OBJ = $(SRC:.c=.o)

NAME=libft.a

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) ./a.out

re: fclean all
