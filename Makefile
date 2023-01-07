# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 18:38:12 by realdahh          #+#    #+#              #
#    Updated: 2023/01/07 09:52:04 by realdahh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CFLAGS	= -g -Wall -Wextra -Werror 
CC		= gcc
CFILES	= libft.c\
			lists.c\
		  split.c\
		  moves.c\
		  stack.c\
		  push_swap.c\
		  radix_sort.c\
		  simple_sort.c\
		  handle_error.c\
		  find_min_max.c\
		  call_rotate.c\
		  call_revers.c\
		  call_swap_push.c

OBJECTS		= 	$(CFILES:.c=.o)
		  
$(NAME): 	$(OBJECTS)
			$(CC) $(OBJECTS) -o $(NAME)

RM		= rm -rf
all:		$(NAME) 

clean: 
			rm -rf $(OBJECTS)

fclean:		 clean 
			rm -rf $(NAME)

re: clean all 

.PHONY: all clean fclean re
