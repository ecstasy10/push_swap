PUSH_SWAP =			push_swap
NAME =				$(PUSH_SWAP)
LIBFT_A =			libft.a

FLAGS =				-Wall -Werror -Wextra

# TODO - FIX RELINK
# CUIDADO CON EL RELINK
COMP =				gcc $(FLAGS) -I includes -I libft/includes -I libft/libft -c -o

OBJ_DIR =			obj/
SRC_DIR =			src/
TOOLS_DIR =			src/tools/
LIBFT =				libft/

SRC =				push_swap.c \
					initialize_frame.c \
					error_check.c \
					manage_stack.c \
					validate.c \
					small_sort.c \
					manage_limits.c \
					manage_moves.c \
					medium_sort.c \
					large_sort.c \
					manage_quarters.c

TOOLS =				free_frame.c \
					parse.c \
					a_ops.c \
					b_ops.c \
					a_b_ops.c \
					sort_array.c

TOOLS_OBJ =			$(TOOLS:%.c=%.o)
SRC_OBJ =			$(SRC:%.c=%.o)
OBJ =				$(TOOLS_OBJ) $(SRC_OBJ)

TOOLS_PATH =   		$(TOOLS:%=$(TOOLS_DIR)%)
PS_SRC_PATH =   	$(SRC:%=$(SRC_DIR)%)
SRC_PATH =			$(TOOLS_PATH) $(PS_SRC_PATH)

TOOLS_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(TOOLS_OBJ))
SRC_OBJ_PATH =		$(addprefix $(OBJ_DIR), $(SRC_OBJ))
OBJ_PATH =			$(TOOLS_OBJ_PATH) $(SRC_OBJ_PATH)

all:			color do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n\033[32;1m PUSH_SWAP DONE \033[0m \\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):		$(OBJ_PATH)
				@gcc $(TOOLS_OBJ_PATH) $(SRC_OBJ_PATH) *.a -o push_swap \
					-I includes -I libft/includes

$(TOOLS_OBJ_PATH):	$(TOOLS_PATH)
				@$(MAKE) $(TOOLS_OBJ)

$(SRC_OBJ_PATH):	$(SRC_PATH)
				@$(MAKE) $(SRC_OBJ)

$(TOOLS_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(TOOLS_DIR)$(@:%.o=%.c)

$(SRC_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT)
				@cp $(LIBFT)/$(LIBFT_A) .

colour:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			color
				@/bin/rm -rf $(OBJ_DIR) $(LIBFT_A)
				@make -C $(LIBFT) clean
				@echo "\\n\033[32;1m Cleaned libft object files \033[0m"

fclean:			clean
				@/bin/rm -f $(PUSH_SWAP) $(LIBFT_A)
				@make -C $(LIBFT) fclean
				@echo "\\n\033[32;1m Cleaned $(NAME) \033[0m \\n"

re: 			fclean all

.PHONY:			all clean flcean re color