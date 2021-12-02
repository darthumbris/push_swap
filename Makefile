NAME = push_swap

FLAGS = -Wall -Werror -Wextra -g 

LIBFT_DIR = ./libs/libft
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

LIBFT = $(LIBFT_DIR)/libft.a

SRC = 	$(SRC_DIR)/check_input.c \
		$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/exit_message.c \
		$(SRC_DIR)/stack/fill_stack.c \
		$(SRC_DIR)/stack/stack_functions.c \
		$(SRC_DIR)/stack/stack_a_operations.c \
		$(SRC_DIR)/stack/stack_b_operations.c \
		$(SRC_DIR)/stack/combined_operations.c \
		$(SRC_DIR)/stack/indexer.c \
		$(SRC_DIR)/sorters/select_sorter.c \
		$(SRC_DIR)/sorters/sort_three.c \
		$(SRC_DIR)/sorters/check_sorted.c \
		$(SRC_DIR)/sorters/quick_sort.c \
		$(SRC_DIR)/sorters/big_sorter.c \
		$(SRC_DIR)/sorters/sort_utils.c \
		$(SRC_DIR)/sorters/chunk_sort.c \
		$(SRC_DIR)/sorters/chunk_sort_utils.c \
		$(SRC_DIR)/sorters/radix_sort.c \
		$(SRC_DIR)/commands/com_list_functions.c 

OBJ = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC:.c=.o))

INC = -I $(INC_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

#%.o: %.c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	gcc $(FLAGS) $(INC) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re