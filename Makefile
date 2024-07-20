CC := gcc

CFLAGS := -Wall -Wextra -Werror

SRCS := push_swap.c\
		parse.c\
		global_instructions.c common_instructions.c a_instructions.c b_instructions.c\
		algo_functions.c sort_3.c push_to_stack.c\
		utils.c\

OBJS := $(SRCS:.c=.o)

NAME := push_swap

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(NAME)
fclean:
	rm -f $(OBJS)
re: fclean all

.PHONY: all clean