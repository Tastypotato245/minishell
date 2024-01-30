# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 18:55:32 by kyusulee          #+#    #+#              #
#    Updated: 2024/01/28 18:28:16 by kyusulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libkyusulib.a

LIBFT		=	./libft/
EXCEPT		=	./ft_except/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)
EXCEPT_A	=	$(addprefix $(EXCEPT), libftexcept.a)

ARX			=	ar x
AR			=	ar rc
CC			=	cc
CFLAGS		=	-Werror -Wall -Wextra
RM			=	rm -f
ECHO		=	echo

all			:	$(NAME)
				@$(ECHO) "*** Make <kyusulib> complete."

$(NAME)		:	$(LIBFT_A) $(EXCEPT_A)
				@$(ARX) $(LIBFT_A)
				@$(ARX) $(EXCEPT_A)
				@$(AR) $(NAME) *.o
				@$(RM) *.o

$(LIBFT_A)	:
				@$(MAKE) -C $(LIBFT)

$(EXCEPT_A)	:
				@$(MAKE) -C $(EXCEPT)

clean		:
				@$(MAKE) -C $(LIBFT) clean
				@$(MAKE) -C $(EXCEPT) clean
				@$(ECHO) "*** Clean <kyusulib>."

fclean		:
				@$(MAKE) -C $(LIBFT) fclean
				@$(MAKE) -C $(EXCEPT) fclean
				@$(RM) __.SYMDEF\ SORTED
				@$(RM) $(NAME)
				@$(ECHO) "*** Fclean <kyusulib>."

re			:
				@$(ECHO) "*** Re-make <kyusulib> start."
				@$(MAKE) fclean
				@$(MAKE) all
				@$(ECHO) "*** Re-make <kyusulib> complete."

.PHONY		:	all clean fclean re
