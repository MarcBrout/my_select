/*
** my_select.h for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec  1 13:44:57 2015 marc brout
** Last update Thu Dec 10 21:07:12 2015 marc brout
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_
# define MY_KEY_SPACE 32
# define MY_CTRL_A 1
# define MY_CTRL_W 23
# define MY_CTRL_B 2

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
  int			search;
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
  SCREEN		*screen;
  int			x;
  int			y;
  int			pos;
  int			len;
  int			strl;
  char			selecta;
  int			*keytab;
  void			(**pfunc)(struct s_wrk *);
}			t_wrk;

int add_elem_to_list(t_wrk *, t_arg *, char *);
t_arg *advance(t_wrk *, t_arg *);
int create_first_elem(t_wrk *, char *);
void delete_node(t_wrk *);
t_arg *delete_node_sel(t_wrk *, t_arg *);
void del_select(t_wrk *);
void free_list(t_wrk *);
void init_keytab(t_wrk *);
void init_pfunc(t_wrk *);
char init_tabs(t_wrk *);
char init_window(t_wrk *);
void move_key(t_wrk *, int);
void move_left(t_wrk *);
void move_next(t_wrk *);
void move_prev(t_wrk *);
void move_right(t_wrk *);
void my_put_stch_underline(t_wrk *, char *);
void my_put_stch_bgcolor(t_wrk *, char *);
void my_put_stch_both(t_wrk *, char *);
void my_put_stnorm(t_wrk *, char *);
char on_going_win(t_wrk *);
void print_string_mode(t_wrk *, t_arg *);
void put_user_select(t_wrk *);
void put_str_select(t_arg *, char *);
char put_error(t_wrk *, char);
int put_usage(int);
char resize_window(t_wrk *);
void select_all(t_wrk *);
void select_inv(t_wrk *);
void select_it(t_wrk *);
void show_list(t_wrk *);

#endif
