NAME		=	push_swap
BONUS		= checker
CC			=	cc
CFLAGS	=	-Wall -Wextra -Werror
LIBFT		=	libft/libft.a
INC		=	-I ./src -I ./libft -I ./src_bonus -I ./gnl
OBJ		=	$(patsubst src/%.c, obj/%.o, $(SRC))
SRC		=	src/push_swap.c \
				src/push_swap_utils.c \
				src/algorithm.c \
				src/p_s_functions.c \
				src/rotate_functions.c \
				src/sort_algorithm.c

OBJ_BONUS	=	obj/checker_bonus.o \
					obj/checker_utils_bonus.o \
					obj/get_next_line.o \
					obj/get_next_line_utils.o

SRC_BONUS	=	src_bonus/checker_bonus.c \
					src_bonus/checker_utils.c

SRC_GNL			=	gnl/get_next_line.c \
					gnl/get_next_line_utils.c

SHARED_OBJ	=	obj/push_swap_utils.o \
					obj/p_s_functions.o \
					obj/rotate_functions.o

all:		$(LIBFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
			@echo "\n\033[1;32m✅ push_swap compiled!"

bonus:		$(LIBFT) obj $(BONUS)

$(BONUS):	$(OBJ_BONUS) $(SHARED_OBJ)
				$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
				@echo "\n\033[1;32m✅ Checker compiled!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

obj/%.o:	src_bonus/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

obj/%.o:	gnl/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(LIBFT):		
			@make -s -C libft
			@echo "Libft compiled!"

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) $(BONUS_OBJ) $(LIBFT) obj
			@echo "\033[1;35mObjects deleted."

fclean:	clean
			@make -s fclean -C libft
			@rm -rf $(NAME) $(BONUS)
			@echo "\033[1;36mPush_swap and checker deleted."

re:			fclean all

.PHONY:		all bonus clean fclean re
