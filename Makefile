# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 19:56:05 by kyusulee          #+#    #+#              #
#    Updated: 2024/02/08 13:24:54 by kyusulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

HEAD		=	$(INCL_DIR)builtin.h	\
				$(INCL_DIR)dict.h	\
				$(INCL_DIR)execute.h	\
				$(INCL_DIR)expansion.h	\
				$(INCL_DIR)here_document.h	\
				$(INCL_DIR)kyusulib.h	\
				$(INCL_DIR)list.h	\
				$(INCL_DIR)minishell.h	\
				$(INCL_DIR)panic.h	\
				$(INCL_DIR)parse.h	\
				$(INCL_DIR)signal_handler.h	\
				$(INCL_DIR)tokenize.h	\
				$(INCL_DIR)traverse.h	\
				$(INCL_DIR)ui.h	\
				$(INCL_DIR)vector.h


HEAD_B		=	$(INCL_DIR)builtin_bonus.h	\
				$(INCL_DIR)dict_bonus.h	\
				$(INCL_DIR)execute_bonus.h	\
				$(INCL_DIR)expansion_bonus.h	\
				$(INCL_DIR)here_document_bonus.h	\
				$(INCL_DIR)kyusulib_bonus.h	\
				$(INCL_DIR)list_bonus.h	\
				$(INCL_DIR)minishell_bonus.h	\
				$(INCL_DIR)panic_bonus.h	\
				$(INCL_DIR)parse_bonus.h	\
				$(INCL_DIR)signal_handler_bonus.h	\
				$(INCL_DIR)tokenize_bonus.h	\
				$(INCL_DIR)traverse_bonus.h	\
				$(INCL_DIR)ui_bonus.h	\
				$(INCL_DIR)vector_bonus.h

SRCS		=	$(SRCS_DIR)main.c	\
				$(SRCS_DIR)ui_symbol.c	\
				$(SRCS_DIR)tokenize.c							\
				$(SRCS_DIR)tokenize_categorize_token.c			\
				$(SRCS_DIR)tokenize_create_token1.c				\
				$(SRCS_DIR)tokenize_create_token2.c				\
				$(SRCS_DIR)tokenize_create_token3.c				\
				$(SRCS_DIR)tokenize_check_validity_of_tokens.c	\
				$(SRCS_DIR)tokenize_print_token.c				\
				$(SRCS_DIR)tokenize_utils.c						\
				$(SRCS_DIR)parse.c					\
				$(SRCS_DIR)parse_list.c				\
				$(SRCS_DIR)parse_pipeline.c			\
				$(SRCS_DIR)parse_simple_command.c	\
				$(SRCS_DIR)parse_word.c				\
				$(SRCS_DIR)parse_redirection.c		\
				$(SRCS_DIR)parse_print_tree.c		\
				$(SRCS_DIR)parse_destroy_tree.c		\
				$(SRCS_DIR)parse_error_handling.c	\
				$(SRCS_DIR)here_document.c			\
				$(SRCS_DIR)here_document_unlink.c	\
				$(SRCS_DIR)here_document_utils.c	\
				$(SRCS_DIR)traverse.c	\
				$(SRCS_DIR)expansion_ctl1.c				\
				$(SRCS_DIR)expansion_ctl2.c				\
				$(SRCS_DIR)expansion_parameter.c		\
				$(SRCS_DIR)expansion_parameter_utils.c		\
				$(SRCS_DIR)expansion_quote_removal.c	\
				$(SRCS_DIR)expansion_filename.c			\
				$(SRCS_DIR)vector.c				\
				$(SRCS_DIR)vector_push_str.c	\
				$(SRCS_DIR)panic.c		\
				$(SRCS_DIR)list_cmd_ctl.c	\
				$(SRCS_DIR)list_exe_ctl.c	\
				$(SRCS_DIR)list_rd_ctl.c	\
				$(SRCS_DIR)dict_ctl1.c	\
				$(SRCS_DIR)dict_ctl2.c	\
				$(SRCS_DIR)dict_ctl3.c	\
				$(SRCS_DIR)dict_ctl4.c	\
				$(SRCS_DIR)builtin_ctl1.c	\
				$(SRCS_DIR)builtin_ctl2.c	\
				$(SRCS_DIR)builtin_echo.c	\
				$(SRCS_DIR)builtin_cd.c		\
				$(SRCS_DIR)builtin_pwd.c	\
				$(SRCS_DIR)builtin_export.c	\
				$(SRCS_DIR)builtin_unset.c	\
				$(SRCS_DIR)builtin_env.c	\
				$(SRCS_DIR)builtin_exit.c	\
				$(SRCS_DIR)execute_pipex.c			\
				$(SRCS_DIR)execute_pipex_utils.c	\
				$(SRCS_DIR)execute_access.c			\
				$(SRCS_DIR)execute_process.c		\
				$(SRCS_DIR)signal_handler.c


SRCS_B		=	$(SRCS_B_DIR)main_bonus.c	\
				$(SRCS_B_DIR)ui_symbol_bonus.c	\
				$(SRCS_B_DIR)tokenize_bonus.c							\
				$(SRCS_B_DIR)tokenize_categorize_token_bonus.c			\
				$(SRCS_B_DIR)tokenize_create_token1_bonus.c				\
				$(SRCS_B_DIR)tokenize_create_token2_bonus.c				\
				$(SRCS_B_DIR)tokenize_create_token3_bonus.c				\
				$(SRCS_B_DIR)tokenize_check_validity_of_tokens_bonus.c	\
				$(SRCS_B_DIR)tokenize_print_token_bonus.c				\
				$(SRCS_B_DIR)tokenize_utils_bonus.c						\
				$(SRCS_B_DIR)parse_bonus.c					\
				$(SRCS_B_DIR)parse_list_bonus.c				\
				$(SRCS_B_DIR)parse_pipeline_bonus.c			\
				$(SRCS_B_DIR)parse_simple_command_bonus.c	\
				$(SRCS_B_DIR)parse_word_bonus.c				\
				$(SRCS_B_DIR)parse_redirection_bonus.c		\
				$(SRCS_B_DIR)parse_print_tree_bonus.c		\
				$(SRCS_B_DIR)parse_destroy_tree_bonus.c		\
				$(SRCS_B_DIR)parse_error_handling_bonus.c	\
				$(SRCS_B_DIR)here_document_bonus.c			\
				$(SRCS_B_DIR)here_document_unlink_bonus.c	\
				$(SRCS_B_DIR)here_document_utils_bonus.c	\
				$(SRCS_B_DIR)traverse_bonus.c	\
				$(SRCS_B_DIR)expansion_ctl1_bonus.c				\
				$(SRCS_B_DIR)expansion_ctl2_bonus.c				\
				$(SRCS_B_DIR)expansion_parameter_bonus.c		\
				$(SRCS_B_DIR)expansion_parameter_utils_bonus.c		\
				$(SRCS_B_DIR)expansion_quote_removal_bonus.c	\
				$(SRCS_B_DIR)expansion_filename_bonus.c			\
				$(SRCS_B_DIR)vector_bonus.c				\
				$(SRCS_B_DIR)vector_push_str_bonus.c	\
				$(SRCS_B_DIR)panic_bonus.c		\
				$(SRCS_B_DIR)list_cmd_ctl_bonus.c	\
				$(SRCS_B_DIR)list_exe_ctl_bonus.c	\
				$(SRCS_B_DIR)list_rd_ctl_bonus.c	\
				$(SRCS_B_DIR)dict_ctl1_bonus.c	\
				$(SRCS_B_DIR)dict_ctl2_bonus.c	\
				$(SRCS_B_DIR)dict_ctl3_bonus.c	\
				$(SRCS_B_DIR)dict_ctl4_bonus.c	\
				$(SRCS_B_DIR)builtin_ctl1_bonus.c	\
				$(SRCS_B_DIR)builtin_ctl2_bonus.c	\
				$(SRCS_B_DIR)builtin_echo_bonus.c	\
				$(SRCS_B_DIR)builtin_cd_bonus.c		\
				$(SRCS_B_DIR)builtin_pwd_bonus.c	\
				$(SRCS_B_DIR)builtin_export_bonus.c	\
				$(SRCS_B_DIR)builtin_unset_bonus.c	\
				$(SRCS_B_DIR)builtin_env_bonus.c	\
				$(SRCS_B_DIR)builtin_exit_bonus.c	\
				$(SRCS_B_DIR)execute_pipex_bonus.c			\
				$(SRCS_B_DIR)execute_pipex_utils_bonus.c	\
				$(SRCS_B_DIR)execute_access_bonus.c			\
				$(SRCS_B_DIR)execute_process_bonus.c		\
				$(SRCS_B_DIR)signal_handler_bonus.c

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

# FrankShell Logo and Symbol
ASSET		=	./asset/

# kyusulib
KYUSULIB	=	./kyusulib/

SRCS_DIR	=	./src/
SRCS_B_DIR	=	./src_bonus/
INCL_DIR	=	./include/
INCL_B_DIR	=	./include_bonus/

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror # -g -fsanitize=address
RM			=	rm -f
ECHO		=	echo

ifdef WITH_BONUS
    OBJS_SWITCH		= $(OBJS_B)
	HEAD_SWITCH		= $(HEAD_B)
else
    OBJS_SWITCH		= $(OBJS)
	HEAD_SWITCH		= $(HEAD)
endif

ifdef WITH_DEBUG
	DEBUG_SWITCH	= -D DEBUG=1
else
	DEBUG_SWITCH	= -D DEBUG=0
endif

all			:
				@$(MAKE) $(NAME)
				@$(ECHO) "*** Make <Frankshell (minishell)> complete."

bonus		:	
				@$(MAKE) WITH_BONUS=1 $(NAME)
				@$(ECHO) "*** Make <Frankshell (minishell)> complete. (BONUS)"

debug		:
				@$(MAKE) WITH_DEBUG=1 $(NAME)
				@$(ECHO) "*** Make <Frankshell (minishell)> complete. (DEBUG)"

$(NAME)		:	$(OBJS_SWITCH) $(HEAD_SWITCH)
				@$(MAKE) -C $(KYUSULIB)
				@$(MAKE) -C $(ASSET)
				@$(CC) $(CFLAGS) -I$(INCL_DIR) $(OBJS_SWITCH) -L$(KYUSULIB) -lkyusulib -lreadline -o $(NAME)
				@$(ECHO) "*** Linking complete."

clean		:
				@$(MAKE) clean -C $(KYUSULIB)
				@$(MAKE) clean -C $(ASSET)
				@$(RM) $(OBJS)
				@$(RM) $(OBJS_B)
				@$(ECHO) "*** Clean <Frankshell (minishell)>."

fclean		:
				@$(MAKE) fclean -C $(KYUSULIB)
				@$(MAKE) fclean -C $(ASSET)
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
				@$(CC) $(CFLAGS) -I$(INCL_DIR) -c $^ -o $@ $(DEBUG_SWITCH)

test		:	all
				./$(NAME)

.PHONY		:	all clean fclean re bonus test debug
