/*
** my_select.h for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec  1 13:44:57 2015 marc brout
** Last update Thu Dec  3 11:31:08 2015 marc brout
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_
# define MY_KEY_SPACE 32
# define MY_KEY_BSPACE 263

# include <signal.h>
# include <ncurses/curses.h>
# include <unistd.h>
# include <stdlib.h>
# include "my.h"

typedef	struct		s_arg
{
  char			*str;
  char			select;
  char			cursor;
  struct s_arg		*next;
  struct s_arg		*prev;
}			t_arg;

typedef struct		s_win
{
  int			h;
  int			w;
  int			col;
}			t_win;

typedef struct		s_wrk
{
  t_arg			*arg;
  t_arg			*cur;
  t_win			*win;
  int			len;
  int			strmlen;
}			t_wrk;

int add_elem_to_list(t_wrk *, t_arg *, char *);
int create_first_elem(t_wrk *, char *);
char on_going_win(t_wrk *);
void *resize_window(t_wrk *);
void select_it(t_wrk *);
void move_next(t_wrk *);
void move_prev(t_wrk *);
void move_key(t_wrk *, int);
void show_list(t_wrk *);
void init_window(t_wrk *);

#endif
