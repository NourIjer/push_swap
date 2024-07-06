# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address 

# Source files
SRCS := push_swap.c\
		parse.c\
		global_instructions.c common_instructions.c a_instructions.c b_instructions.c indexing.c push_to_stack.c algo_functions.c sort_3.c\

# Object files
OBJS := $(SRCS:.c=.o)

# Target executable
TARGET := push_swap

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and the target executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
