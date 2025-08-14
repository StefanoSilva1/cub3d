NAME = libft.a

CC = cc
FLAGS = -Wall -Werror -Wextra -I../includes
INCLUDE = ../minishell.h
OBJ_DIR = obj/
LIBFT = libft/ft_isspace.c libft/ft_putstr_fd.c libft/ft_strncmp.c

SRC = $(LIBFT)
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONE: all clean fclean re