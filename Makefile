NAME	= libftprintf.a
CC		= gcc
CCFLAG	= -Wall -Werror -Wextra
RM		= rm -f
AR		= ar rcs

SRC 	= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o : %.c
	@$(CC) $(CCFLAG) -c $< -o $@

norminette:
	@norminette

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re norminette
