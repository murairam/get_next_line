# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:28:42 by mmiilpal          #+#    #+#              #
#    Updated: 2023/12/16 19:33:58 by mmiilpal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

INCLUDES := inc/get_next_line.h

SRCS := get_next_line.c \
		get_next_line_utils.c

SRCS := $(addprefix srcs/, $(SRCS))

OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))

CC := cc
CFLAGS := -Wall -Werror -Wextra

# COLORS := $(shell seq 31 37)

INDI	=	\033[38;5;99m
GREEN	=	\033[0;32m
RESET	=	\033[00m

all: create_dirs $(NAME) $(INCLUDES)

main: main.c libftprintf.a
	@cc main.c libftprintf.a && ./a.out

create_dirs:
	@if [ ! -d "objs" ]; then mkdir objs; fi

objs/%.o: srcs/%.c $(INCLUDES)
# @COLOR_CODE=$$(echo "$(COLORS)" | awk '{srand(); print int(rand()*7)}'); \
# printf "\033[1;%sm\t\tCompiling: $<\033[0m\r" $$((30+COLOR_CODE));
	@$(CC) $(CFLAGS) -c $< -o $@;

clean:
	@if [ -d "objs" ]; then rm -rf objs && echo "$(INDI)Object files have been deleted\$(RESET)"; fi

fclean: clean
	@if [ -f "libftprintf.a" ]; then rm -rf libftprintf.a  && echo "$(GREEN)Libray file has been deleted\$(RESET)"; fi

re: fclean all

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

.PHONY: all clean fclean re create_dirs main
