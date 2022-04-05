NAME = pipex

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = pipex.c \
	utils/free/free_utils.c \
	utils/gnl/get_next_line_utils.c \
	utils/gnl/get_next_line.c \
	utils/pipex/pipex_utils_2.c \
	utils/pipex/pipex_utils.c \
	utils/string/split.c \
	utils/string/string_utils_1.c \
	utils/string/string_utils_2.c \

OBJ = ${SRC:.c=.o}

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@ -D BUFFER_SIZE=42
	
$(NAME): $(OBJ)

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY: re fclean all clean