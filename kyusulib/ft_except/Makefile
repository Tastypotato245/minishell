# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 13:38:59 by kyusulee          #+#    #+#              #
#    Updated: 2024/01/15 17:46:13 by kyusulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftexcept.a

HEAD	=	ft_except.h
SRCS	=	ft_except.c	\
			ft_free.c
OBJS	=	$(SRCS:.c=.o)

AR		=	ar -rc
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

ECHO	=	echo

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@$(AR) $@ $^
			@$(ECHO) "*** Make <libftexcept.a>."

clean	:
			@$(RM) $(OBJS)
			@$(ECHO) "*** Clean <libftexcept>."

fclean	:
			@$(RM) $(OBJS)
			@$(RM) $(NAME)
			@$(ECHO) "*** Fclean <libftexcept>."

re		:
			@$(ECHO) "*** Re-make <libftexcept> start."
			@$(MAKE) fclean
			@$(MAKE) all
			@$(ECHO) "*** Re-make <libftexcept> complete."

%.o		:	%.c
			@$(CC) $(CFLAGS) -o $@ -c $^ -include $(HEAD)

.PHONY: all clean fclean re
