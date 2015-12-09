/*
** select.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec  1 13:40:18 2015 marc brout
** Last update Wed Dec  9 20:22:25 2015 marc brout
*/

#include "my_select.h"

char		resize_window(t_wrk *wrk)
{
  int		col;

  getmaxyx(stdscr, wrk->win->h, wrk->win->w);
  wrk->win->col = wrk->win->w / (wrk->strl + 2);
  col = wrk->len / wrk->win->h;
  col += (wrk->len % wrk->win->h) ? 1 : 0;
  if (col > wrk->win->col)
    return (1);
  return (0);
}

char		on_going_win(t_wrk *wrk)
{
  int		key;
  t_win		twin;

  noecho();
  set_escdelay(0);
  wrk->win = &twin;
  resize_window(wrk);
  show_list(wrk);
  wrk->pos = 0;
  while ((key = getch()) && key != 27 && key != '\n')
    {
      resize_window(wrk);
      move_key(wrk, key);
      if (!wrk->len)
	return (2);
      show_list(wrk);
    }
  endwin();
  return (0);
}			     

void		init_window(t_wrk *wrk)
{
  initscr();
  curs_set(0);
  keypad(stdscr, TRUE);
  wrk->arg->cursor = 1;
  wrk->cur = wrk->arg;
  wrk->x = 0;
  wrk->y = 0;
  wrk->pos = 0;
}

char		put_error(t_wrk *wrk, char err)
{
  if (err)
    {
      endwin();
      if (err == 1)
	write(2, "List too big for the window\n", 29);
      if (err == 2)
	write(2, "No more argument in the list\n", 30);
      return (1);
    }
  else
    put_user_select(wrk);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_wrk		wrk;
  int		i;

  if (ac < 2 || env[0] == NULL)
    return (1);
  if (create_first_elem(&wrk, av[1]))
    return (1);
  i = 2;
  while (av[i])
    if (add_elem_to_list(&wrk, wrk.arg, av[i++]))
      return (1);
  init_window(&wrk);
  if (put_error(&wrk, on_going_win(&wrk)))
    return (1);
  return (0);
}
