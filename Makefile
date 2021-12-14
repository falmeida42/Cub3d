NAME = cub

FT_DIR		= libft
SRC_DIR		= src
OBJ_DIR   	= obj
INC_DIRS	= includes $(FT_DIR)

SRCS		= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS 		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC_FLAGS	= $(addprefix -I, $(INC_DIRS))
WARN_FLAGS	= -Wall -Wextra -Werror -Imlx
DEBUG_FLAGS = -g

CFLAGS		= $(WARN_FLAGS) $(INC_FLAGS)

CC			= gcc
RM			= rm -f

RED			= \033[0;31m
GREEN		= \033[0;32m
ORANGE		= \033[0;33m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
NC			= \033[0m

all: 		libft $(NAME)

libft:
			@echo "\n$(GREEN)Compiling libft:$(NC)"
			@$(MAKE) -C $(FT_DIR)

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(dir $@)
			@echo "Creating object: $@"
			@$(CC) $(CFLAGS) -c $< -o $@

# Linking
$(NAME):	$(OBJS)
			@echo "Creating binary: $@"
			@$(CC) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LDFLAGS)

#Cleaning
clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(MAKE) -C $(FT_DIR) clean
			@echo "$(GREEN)libft objects removed!$(NC)"

fclean: clean
			@rm -f $(OBJS)
			@rm -f $(NAME)
			@$(MAKE) -C $(FT_DIR) fclean

# Rebuild
re:			fclean all

# Debugging build
debug:		CFLAGS += $(DEBUG_FLAGS)
debug:		LDFLAGS += $(DEBUG_FLAGS)
debug:		re

.PHONY:		all clean fclean re libft debug