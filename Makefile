# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 19:56:05 by kyusulee          #+#    #+#              #
#    Updated: 2024/01/29 17:57:43 by kyusulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

HEAD		=	$(INCL_DIR)minishell.h
HEAD_B		=	$(INCL_DIR)minishell_bonus.h

SRCS		=	$(SRCS_DIR)main.c	\
				$(SRCS_DIR)print_frankshell_image.c	\
				$(SRCS_DIR)cmd_lst_ctl.c	\
				$(SRCS_DIR)exe_lst_ctl.c	\
				$(SRCS_DIR)rd_lst_ctl.c		\
				$(SRCS_DIR)execute_test.c

SRCS_B		=	$(SRCS_B_DIR)main.c

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

KYUSULIB	=	./kyusulib/

SRCS_DIR	=	./src/
SRCS_B_DIR	=	./src_bonus/
INCL_DIR	=	./include/

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
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

.PHONY		:	all clean fclean re bonus
