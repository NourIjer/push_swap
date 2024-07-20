CC := cc

CFLAGS := -Wall -Wextra -Werror

SRCS := push_swap.c\
		parse.c\
		global_instructions.c common_instructions.c a_instructions.c b_instructions.c\
		algo_functions.c sort_small.c push_to_stack.c\
		utils.c\

OBJS := $(SRCS:.c=.o)

HEADERS := push_swap.h

NAME := push_swap

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: clean fclean