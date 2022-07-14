
SRCS =		${wildcard ./functions/*.c}

OBJS 		= ${SRCS:.c=.o}

CC			= gcc -g
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -Imlx

%.o: %.c
			$(CC) ${CFLAGS} -c $< -o $@

NAME		= so_long


$(NAME):	$(OBJS)
			$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:		${NAME}

clean:
			${RM} ${OBJS}
			@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:		clean
			${RM} ${NAME}
			@echo -e "$(RED)all deleted!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
