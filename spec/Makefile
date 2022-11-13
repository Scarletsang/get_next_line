# Please only change the following line
TARGET_NAMES=get_next_line_utils.c get_next_line.c

NAME=debug.out
TARGET_DIR=../src
TESTS:= $(shell find tests -name '*.c')
TARGETS=$(addprefix ${TARGET_DIR}/,${TARGET_NAMES})
TARGETS_OBJS=${TARGETS:.c=.o}
TESTS_OBJS=${TESTS:.c=.o}
CC=cc
CFLAGS= -g

all: ${NAME}

${NAME}: ${TARGETS_OBJS} ${TESTS_OBJS}
ifeq ($(findstring .a, ${TARGETS}),)
	${CC} -g -Wformat main.c ${TESTS_OBJS} ${TARGETS_OBJS} -o ${NAME} && \
	echo "Success compiling with the target binary ${TARGET_NAMES}!"
else
	@${CC} -g -Wformat main.c ${TESTS_OBJS} -L./${TARGET_DIR} -l$(patsubst lib%.a,%,${TARGET_NAMES}) -o ${NAME} && \
	echo "Success compiling with the target library ${TARGET_NAMES}!"
endif

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean: targetclean
	@rm -f ${TESTS_OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

# Target rules

${TARGETS_OBJS}: ${TARGETS}
	${CC} -g -Wall -Werror -Wextra -c $*.c -o $@

targetclean:
	@rm -f ${TARGETS_OBJS}