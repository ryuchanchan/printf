NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ./src/ft_printf.c ./src/utils.c ./src/put_types.c ./src/base_nbr.c
LIBS	= libft.a
OBJS	= $(SRCS:.c=.o)
INCS	= ./include
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)

#.c.o:
%.o: %.c
	${CC} ${FLAGS} -I ${INCS} -c $< -o ${<:.c=.o}
re: fclean all
fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft
clean:
	$(RM) $(OBJS)
	make clean -C ./libft
.PHONY: all clean fclean re