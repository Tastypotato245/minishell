# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 16:41:52 by kyusulee          #+#    #+#              #
#    Updated: 2024/01/15 12:36:52 by kyusulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

AR		=	ar -rc
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

HEAD	=	./libft.h
SRCS	=	ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_split.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strlen.c		\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strtrim.c	\
			ft_substr.c		\
			ft_tolower.c	\
			ft_toupper.c
OBJS	=	$(SRCS:.c=.o)

SRCS_BO	=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJS_BO	=	$(SRCS_BO:.c=.o)

RM		=	rm -f
ECHO	=	echo

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(AR) $(NAME) $^
	@$(ECHO) "*** Make <libft.a>."

bonus	:	$(OBJS_BO)
	@$(AR) $(NAME) $^
	@touch $@
	@$(ECHO) "*** Make <libft.a> bonus version."

clean	:
	@$(RM) $(OBJS) $(OBJS_BO)
	@$(RM) bonus 
	@$(ECHO) "*** Clean <libft>."

fclean	:
	@$(RM) $(OBJS) $(OBJS_BO)
	@$(RM) bonus 
	@$(RM) $(NAME)
	@$(ECHO) "*** Fclean <libft>."

re		:
	@$(ECHO) "*** Re-make <libft> start."
	@$(MAKE) fclean
	@$(MAKE) all
	@$(ECHO) "*** Re-make <libft> complete."

%.o		:	%.c $(HEAD)
	@$(CC) $(CFLAGS) -o $@ -c $< -include $(HEAD)

.PHONY: all clean fclean re 
