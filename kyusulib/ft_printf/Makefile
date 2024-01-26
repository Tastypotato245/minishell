# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 14:18:18 by kyusulee          #+#    #+#              #
#    Updated: 2024/01/15 12:36:36 by kyusulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

HEAD	=	ft_printf.h
SRCS	=	ft_printf.c ft_printf_libft.c ft_printf_writers.c
OBJS	=	$(SRCS:.c=.o)

AR		=	ar -rc
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

ECHO	=	echo

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@$(AR) $@ $^
			@$(ECHO) "*** Make <libftprintf.a>."

clean	:
			@$(RM) $(OBJS)
			@$(ECHO) "*** Clean <ftprintf>."

fclean	:
			@$(RM) $(OBJS)
			@$(RM) $(NAME)
			@$(ECHO) "*** Fclean <ftprintf>."

re		:
			@$(ECHO) "*** Re-make <ftprintf> start."
			@$(MAKE) fclean
			@$(MAKE) all
			@$(ECHO) "*** Re-make <ftprintf> complete."

%.o		:	%.c
			@$(CC) $(CFLAGS) -o $@ -c $^ -include $(HEAD)

.PHONY: all clean fclean re
