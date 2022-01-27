NAME		=	philo

SRC_PATH 	=	src/
SRC_FILES	=	philo.c\
				utils.c\
				init.c\
				print.c\
				free.c\
				action.c\
				routines.c
SRC			=	${addprefix ${SRC_PATH}, ${SRC_FILES}}

INC_PATH 	=	inc/
INC_FILES	= 	philo.h
INC			=	${addprefix ${INC_PATH}, ${INC_FILES}}

OBJ			=	${SRC:%.c=%.o}

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I${INC_PATH}

RED			=	"\033[1;31m"
BLUE		=	"\033[1;34m"
YELLOW		=	"\033[1;33m"
WHITE		=	"\033[1;37m"
GREEN		=	"\033[1;32m"
PURPLE		=	"\033[1;35m"
GRAY		=	"\033[1;30m"
END			=	"\033[0m"

.PHONY	:	all clean fclean re

all		:	${NAME}

${NAME}	:	${OBJ} ${INC}
			@${CC} ${CFLAGS} ${OBJ} -o ${NAME}
			@echo ${GREEN} "\n< Binary -> done >\n" ${END}

%.o : %.c ${INC}
			@${CC} ${CFLAGS} -c $< -o $@

clean	:
			@rm -f ${OBJ}
			@echo ${YELLOW} "\n< .o files -> removed >\n" ${END}

fclean	:	clean
			@rm -f ${NAME}
			@echo ${YELLOW} "\n< Binaries -> removed >\n" ${END}

re		:	fclean all
			@echo ${PURPLE} "\n< Remake done >\n" ${END}