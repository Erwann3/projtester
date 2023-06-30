##
## EPITECH PROJECT, 2023
## B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
## File description:
## Makefile
##

CC = gcc

NAME = projTester

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -Iinclude

SRCS = src/main.c \
       src/parse_args.c \
       src/directory_helper.c \
       src/parse_file.c \
       src/binary_helper.c \
       src/execute_tests.c \
       src/string_helper.c \
       src/execute_binary.c \
       src/parse_input.c \
       src/write_helper.c \
       src/binary_input.c \
       src/errors.c \
       src/result_helper.c \
       src/awaited_results.c

OBJS = $(SRCS:.c=.o)

SRC_TESTS = tests/tests.c

OBJ_TESTS = $(SRC_TESTS:.c=.o)

TEST_NAME = unit_tests

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

tests_run: CFLAGS += --coverage
tests_run: LDFLAGS += -lcriterion -lgcov
tests_run: $(OBJS) $(OBJ_TESTS)
		$(CC) -o $(TEST_NAME) $(OBJ) $(OBJ_TESTS) $(LDFLAGS)
		./$(TEST_NAME)

.PHONY: all clean fclean re tets_run
