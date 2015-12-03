##
## Makefile for select
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Tue Dec  1 22:51:35 2015 marc brout
## Last update Thu Dec  3 10:54:22 2015 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)my_select.c

OBJS    = $(SRC:.c=.o)

NAME    = my_select

CC      = gcc

CFLAGS  = -W -Wall -ansi -pedantic -g

LDFLAGS = -L./lib/ -lmy -lncurses -I./include/

RM      = rm -f

$(NAME): $(OBJS)
	@($(CC) -o $(NAME) $(OBJS) $(LDFLAGS))

all: $(NAME) 

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
