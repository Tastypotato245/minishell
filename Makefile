# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 19:56:05 by kyusulee          #+#    #+#              #
#    Updated: 2024/01/26 20:02:41 by kyusulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

HEAD		=	$(INCL_DIR)minishell.h
HEAD_B		=	$(INCL_DIR)minishell_bonus.h

SRCS		=	$(SRCS_DIR)main.c		\
				$(SRCS_DIR)tokenize.c	\
				$(SRCS_DIR)tokenize_categorize_token.c	\
				$(SRCS_DIR)tokenize_create_token.c	\
				$(SRCS_DIR)tokenize_print_token.c	\
				$(SRCS_DIR)tokenize_utils.c	\
				$(SRCS_DIR)parser.c	\
				$(SRCS_DIR)vector.c	\
				$(SRCS_DIR)panic.c	\

SRCS_B		=	$(SRCS_B_DIR)main.c		\
				$(SRCS_DIR)tokenize.c	\
				$(SRCS_DIR)tokenize_categorize_token.c	\
				$(SRCS_DIR)tokenize_create_token.c	\
				$(SRCS_DIR)tokenize_print_token.c	\
				$(SRCS_DIR)tokenize_utils.c	\
				$(SRCS_DIR)parser.c	\
				$(SRCS_DIR)vector.c	\
				$(SRCS_DIR)panic.c	\

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

KYUSULIB	=	./kyusulib/

SRCS_DIR	=	./src/
SRCS_B_DIR	=	./src_bonus/
INCL_DIR	=	./include/

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
RM			=	rm -f
ECHO		=	echo

ifdef WITH_BONUS
    OBJS_SWITCH = $(OBJS_B)
	HEAD_SWITCH = $(HEAD_B)
else
    OBJS_SWITCH = $(OBJS)
	HEAD_SWITCH = $(HEAD)
endif

all			:
				@$(MAKE) $(NAME)
				@$(ECHO) "*** Make <Frankshell (minishell)> complete."

bonus		:	
				@$(MAKE) WITH_BONUS=1 $(NAME)
				@$(ECHO) "*** Make <Frankshell (minishell)> complete. (BONUS)"

$(NAME)		:	$(OBJS_SWITCH) $(HEAD_SWITCH)
				@$(MAKE) -C $(KYUSULIB)
				@$(CC) $(CFLAGS) -I$(INCL_DIR) $(OBJS_SWITCH) -L$(KYUSULIB) -lkyusulib -lreadline -o $(NAME)
				@$(ECHO) "*** Linking complete."

clean		:
				@$(MAKE) clean -C $(KYUSULIB)
				@$(RM) $(OBJS)
				@$(RM) $(OBJS_B)
				@$(ECHO) "*** Clean <Frankshell (minishell)>."

fclean		:
				@$(MAKE) fclean -C $(KYUSULIB)
				@$(RM) $(OBJS)
				@$(RM) $(OBJS_B)
				@$(RM) $(NAME)
				@$(ECHO) "*** Fclean <Frankshell (minishell)>."

re			:
				@$(ECHO) "*** Re-make <Frankshell (minishell)> start."
				@$(MAKE) fclean
				@$(MAKE) all
				@$(ECHO) "*** Re-make <Frankshell (minishell)> complete."

%.o			:	%.c
				@$(CC) $(CFLAGS) -I$(INCL_DIR) -c $^ -o $@

test: all
	./$(NAME)

.PHONY		:	all clean fclean re bonus test
