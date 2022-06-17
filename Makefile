# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 08:25:44 by rykawamu          #+#    #+#              #
#    Updated: 2022/06/13 08:25:48 by rykawamu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ./src/ft_printf.c ./src/utils.c ./src/put_types.c ./src/base_nbr.c
LIBS	= libft.a
OBJS	= $(SRCS:.c=.o)
INCS	= ./include

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	${CC} ${CFLAGS} -I ${INCS} -c $< -o ${<:.c=.o}
re: fclean all
fclean: clean
	$(RM) $(NAME)
	@make fclean -C ./libft
clean:
	$(RM) $(OBJS)
	@make clean -C ./libft
.PHONY: all clean fclean re
