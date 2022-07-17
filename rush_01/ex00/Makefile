################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := rush-01
CC        := cc
FLAGS    := -Wall -Wextra -Werror
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      main.c \
					src/check_clue.c \
					src/check_valid.c \
					src/utils.c \
					src/get_map.c \
					src/ft_split.c \
					src/ft_atoi.c \
					src/free.c


OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -I./include -c $< -o ${<:.c=.o} -g

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
