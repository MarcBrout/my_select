/*
** select.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec  1 13:40:18 2015 marc brout
** Last update Thu Dec  3 11:34:25 2015 marc brout
*/

#include "my_select.h"

int		add_elem_to_list(t_wrk *wrk, t_arg *arg, char *str)
{
  t_arg		*elem;

  if (str[0] == 0)
    return (1);
  if ((elem = malloc(sizeof(t_arg))) == NULL)
    return (2);
  elem->str = str;
  elem->cursor = 0;
  elem->select = 0;
  elem->next = arg;
  elem->prev = arg->prev;
  arg->prev->next = elem;
  arg->prev = elem;
  wrk->len += 1;
  return (0);
}

int		create_first_elem(t_wrk *wrk, char *str)
{
  t_arg		*elem;

  if ((elem = malloc(sizeof(t_arg))) == NULL)
    return (2);
  elem->str = str;
  elem->cursor = 1;
  elem->select = 0;
  elem->next = elem;
  elem->prev = elem;
  wrk->arg = elem;
  wrk->len = 1;
  return (0);
}

void		my_put_stch_underline(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    addch(str[i] | A_UNDERLINE);
}

void		my_put_stch_bgcolor(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    addch(str[i] | A_REVERSE);
}

void		my_put_stch_both(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    addch(str[i] | A_UNDERLINE | A_REVERSE);
}

void		print_string_mode(t_arg *arg)
{
  if (arg->cursor && !arg->select)
    my_put_stch_underline(arg->str);
  else if (!arg->cursor && arg->select)
    my_put_stch_bgcolor(arg->str);
  else if (arg->cursor && arg->select)
    my_put_stch_both(arg->str);
  else
    addstr(arg->str);
}

void		show_list(t_wrk *wrk)
{
  t_arg		*tmp;
  int		y;	

  tmp = wrk->arg;
  y = 0;
  while (tmp != wrk->arg->prev)
    {
      print_string_mode(tmp);
      y += 1;
      move(y, 0);
      tmp = tmp->next;
    }
  print_string_mode(tmp);
  move(0, 0);
  refresh();
}

void		delete_node(t_wrk *wrk)
{
  t_arg		*tmp;

  tmp = wrk->cur->next;
  if (wrk->arg == wrk->cur)
    wrk->arg = wrk->arg->next;
  wrk->cur->next->prev = wrk->cur->prev;
  wrk->cur->prev->next = wrk->cur->next;
  if (wrk->cur != NULL)
    free(wrk->cur);
  wrk->cur = tmp;
  wrk->cur->cursor = 1;
  wrk->len -= 1;
}

void		select_it(t_wrk *wrk)
{
  wrk->cur->select = (wrk->cur->select) ? 0 : 1;
  move_next(wrk);
}

void		move_next(t_wrk *wrk)
{
  wrk->cur->cursor = 0;
  wrk->cur = wrk->cur->next;
  wrk->cur->cursor = 1;
}
void		move_prev(t_wrk *wrk)
{
  wrk->cur->cursor = 0;
  wrk->cur = wrk->cur->prev;
  wrk->cur->cursor = 1;
}

void		move_key(t_wrk *wrk, int key)
{
  if (key == KEY_DOWN)
    move_next(wrk);
  if (key == KEY_UP)
    move_prev(wrk);
  if (key == MY_KEY_SPACE)
    select_it(wrk);
  if (key == KEY_DC || key == MY_KEY_BSPACE)
    delete_node(wrk);
  clear();
}

void		*resize_window(t_wrk *wrk)
{
  getmaxyx(stdscr, wrk->win->h, wrk->win->w);
  
}

char		on_going_win(t_wrk *wrk)
{
  int		key;
  t_win		twin;

  noecho();
  wrk->win = &twin;
  show_list(wrk);
  signal(SIGWINCH, resize_window);
  while ((key = getch()) && key != 27 && key != '\n')
    {
      move_key(wrk, key);
      if (!wrk->len)
	return (0);
      show_list(wrk);
    }
  if (key == 27)
    return (0);
  return (1);
}			     

void		init_window(t_wrk *wrk)
{
  initscr();
  curs_set(0);
  keypad(stdscr, TRUE);
  wrk->arg->cursor = 1;
  wrk->cur = wrk->arg;
}

void		put_str_select(t_arg *tmp, char *prec)
{
  if (tmp->select == 1)
    {
      if (*prec)
	my_putchar(' ');
      my_putstr(tmp->str);
      *prec = 1;
    } 
}

void		put_user_select(t_wrk *wrk)
{
  t_arg		*tmp;
  char		prec;

  prec = 0;
  tmp = wrk->arg;
  while (tmp != wrk->arg->prev)
    {
      put_str_select(tmp, &prec);
      tmp = tmp->next;
    }
  put_str_select(tmp, &prec);
}

int		main(int ac, char **av)
{
  t_wrk		wrk;
  int		i;

  if (ac < 2)
    return (1);
  create_first_elem(&wrk, av[1]);
  i = 2;
  while (av[i])
    add_elem_to_list(&wrk, wrk.arg, av[i++]);
  init_window(&wrk);
  if (on_going_win(&wrk))
    {
      endwin();
      put_user_select(&wrk);
    }
  else
    endwin();
  return (0);
}
