NAME		=	push_swap
BONUS		= checker
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LIBFT		=	libft/libft.a
INC			=	-I ./src -I ./libft
OBJ			=	$(patsubst src/%.c, obj/%.o, $(SRC))
SRC			=	src/push_swap.c \
					src/push_swap_utils.c \
					src/algorithm.c \
					src/p_s_functions.c \
					src/rotate_functions.c \
					src/sort_algorithm.c

OBJ_BONUS	=	$(patsubst src_bonus/%.c, obj_bonus/%.o, $(SRC_BONUS))
SRC_BONUS	=	src_bonus/checker_bonus.c \
					src_bonus/checker_utils.c \
					gnl/get_next_line.c \
					gnl/get_next_line_utils.c

all:		$(LIBFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
			@echo "\n\033[1;32m✅ push_swap compiled!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

bonus:		$(LIBFT) obj $(BONUS)

$(BONUS):	$(OBJ) $(BONUS_OBJ)
			$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
			@echo "\n\033[1;32m✅ Checker compiled!"

$(LIBFT):		
			@make -s -C libft
			@echo "Libft compiled!"


obj/%.o:	src_bonus/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) $(BONUS_OBJ) $(LIBFT) obj obj_bonus
			@echo "\033[1;30m🗑️  Objects deleted."

fclean:
			@make -s $@ -C libft

			
			@rm -rf $(NAME) $(BONUS) $(OBJ) $(BONUS_OBJ) $(LIBFT) obj obj_bonus
			@echo "\033[1;30m🗑️  push_swap and checker deleted."

re:			fclean all

.PHONY:		all bonus clean fclean re
