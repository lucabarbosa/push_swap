NAME		=	push_swap
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
					src/sort_max.c

all:		$(LIBFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

$(LIBFT):		
			@make -s -C libft
			@echo "Libft compiled!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "Objects deleted."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "Objects and push_swap deleted."

re:			fclean all

.PHONY:		all clean fclean re
