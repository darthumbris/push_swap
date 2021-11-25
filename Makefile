NAME = push_swap

LIBFT_DIR = ./libs/libft

LIBFT = $(LIBFT_DIR)/libft.a

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

INC = -I ./includes

SRC_DIR = ./src/

SRC = 	$(SRC_DIR)check_input.c \
		$(SRC_DIR)push_swap.c \
		$(SRC_DIR)exit_message.c \
		$(SRC_DIR)stack/fill_stack.c \
		$(SRC_DIR)stack/stack_functions.c \
		$(SRC_DIR)stack/stack_a_operations.c \
		$(SRC_DIR)stack/stack_b_operations.c \
		$(SRC_DIR)stack/combined_operations.c \
		$(SRC_DIR)stack/indexer.c \
		$(SRC_DIR)sorters/select_sorter.c \
		$(SRC_DIR)sorters/sort_three.c \
		$(SRC_DIR)sorters/check_sorted.c \
		$(SRC_DIR)sorters/quick_sort.c \
		$(SRC_DIR)sorters/big_sorter.c \
		$(SRC_DIR)sorters/sort_utils.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re