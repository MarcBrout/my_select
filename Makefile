##
## Makefile for select
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Tue Dec  1 22:51:35 2015 marc brout
## Last update Wed Dec  9 20:56:31 2015 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)my_select.c \
	$(SRCP)lists.c \
	$(SRCP)moves.c \
	$(SRCP)results.c \
	$(SRCP)string_styles.c

OBJS    = $(SRC:.c=.o)

NAME    = my_select

CC      = gcc

CFLAGS  = -W -Wall -ansi -pedantic -g

LDFLAGS = -L./lib/ -lmy -lncurses -I./include/

RM      = rm -f

$(NAME):
	@($(CC) -o $(NAME) $(SRC) $(LDFLAGS))

all: $(NAME) 

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
