NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c \
	utils/free/free_utils.c \
	utils/gnl/get_next_line_utils.c \
	utils/gnl/get_next_line.c \
	utils/pipex/pipex_utils_2.c \
	utils/pipex/pipex_utils.c \
	utils/string/split.c \
	utils/string/string_utils_1.c \

BSRC = pipex_bonus.c \
	utils/pipex/pipex_utils_bonus.c \
	utils/free/free_utils.c \
	utils/gnl/get_next_line_utils.c \
	utils/gnl/get_next_line.c \
	utils/pipex/pipex_utils_2.c \
	utils/pipex/pipex_utils.c \
	utils/string/split.c \
	utils/string/string_utils_1.c \


OBJ = ${SRC:.c=.o}

BOBJ = ${BSRC:.c=.o}

all: $(NAME)
	
$(NAME): $(OBJ)

bonus: $(BOBJ)
	$(CC) $(BOBJ) -o $(NAME)

$(BNAME) : $(BOBJ)

clean :
	rm -f ${OBJ} $(BOBJ)

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY: re fclean all clean
