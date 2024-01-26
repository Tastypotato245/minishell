# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 16:25:35 by kyusulee          #+#    #+#              #
#    Updated: 2024/01/15 12:36:43 by kyusulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libgnl.a

HEAD	=	get_next_line.h
SRCS	=	get_next_line.c get_next_line_utils.c
OBJS	=	$(SRCS:%.c=%.o)

AR		=	ar -rc
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

ECHO	=	echo

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@$(AR) $@ $^
			@$(ECHO) "*** Make <libgnl.a>."

clean	:
			@$(RM) $(OBJS)
			@$(ECHO) "*** Clean <gnl>."

fclean	:
			@$(RM) $(OBJS)
			@$(RM) $(NAME)
			@$(ECHO) "*** Fclean <gnl>."

re		:
			@$(ECHO) "*** Re-make <gnl> start."
			@$(MAKE) fclean
			@$(MAKE) all
			@$(ECHO) "*** Re-make <gnl> complete."

%.o		:	%.c $(HEAD)
			@$(CC) $(CFLAGS) -o $@ -c $< -include $(HEAD)

.PHONY:		all clean fclean re
