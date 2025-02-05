# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlippelt <dlippelt@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 11:41:23 by dlippelt          #+#    #+#              #
#    Updated: 2025/02/05 12:09:26 by dlippelt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=test

#0 to test only mandatory, 1 to test bonus as well
BONUS=0

CC=cc

# FTPRINTFDIR=$(HOME)/codam/main/ft_printf
# INCLDIR=$(HOME)/codam/main/ft_printf
FTPRINTFDIR=$(HOME)/path/to/project/directory
INCLDIR=$(HOME)/path/to/include/directory

IFLAGS=-I$(INCLDIR)
CFLAGS=-Wall -Wextra -Werror

LIBFTPRINTF=$(FTPRINTFDIR)/libftprintf.a

SRCS= main.c

OBJS=$(SRCS:.c=.o)

HDRS=$(INCLDIR)/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $^ $(LIBFTPRINTF) -o $@

%.o: %.c $(HDRS)
	$(CC) -DBONUS=$(BONUS) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf *.gch
	rm -rf *.o
	rm -rf *.txt

fclean: clean
	rm -rf $(NAME)
	rm -rf *.out

re: fclean all

memory: CFLAGS += -g3 -fsanitize=address
memory: re

.PHONY: all clean fclean re memory
