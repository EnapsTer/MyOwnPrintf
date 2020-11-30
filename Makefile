C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = src

PARSE_DIR = src/parse

UTILS_DIR = src/utils

INCLUDES = includes

SRC =	$(DIR_S)/ft_printf.c \
		$(PARSE_DIR)/parse.c \
		$(PARSE_DIR)/parse_integer_value.c \
		$(PARSE_DIR)/parse_pointer_value.c \
		$(PARSE_DIR)/parse_value_manager.c \
		$(PARSE_DIR)/parse_string_value.c	\
		$(PARSE_DIR)/parse_char_value.c \
		$(PARSE_DIR)/parse_hex_value.c \
		$(UTILS_DIR)/num_value_utils.c \
		$(UTILS_DIR)/parse_utils.c \
		$(UTILS_DIR)/string_value_utils.c \
		$(UTILS_DIR)/base_num_value_utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	@$(C) $(FLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT)
	@cp Libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Compile libftprintf.a done!"

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)
	@echo "Clean .o files done!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "Clean libftprintf.a done!"

norme:
	norminette ./$(LIBFT)/
	@echo
	norminette ./$(INCLUDES)/
	@echo
	norminette ./$(DIR_S)/

re: fclean all