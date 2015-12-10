/*
** results.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Dec  9 09:37:51 2015 marc brout
** Last update Wed Dec  9 20:53:02 2015 marc brout
*/

#include "my_select.h"

void		select_it(t_wrk *wrk)
{
  wrk->cur->select = (wrk->cur->select) ? 0 : 1;
  move_next(wrk);
}

t_arg		*advance(t_wrk *wrk, t_arg *arg)
{
  int		i;
  int		c;

  if ((c = ((wrk->pos / (wrk->win->h)) / wrk->win->col)) >=
      (wrk->win->col - 1))
    {
      i = wrk->win->h * (c + 1);
      while (--i > 0)
	arg = arg->next;
    }
  return (arg);
}

void		show_list(t_wrk *wrk)
{
  t_arg		*tmp;

  tmp = wrk->arg;
  tmp = advance(wrk, tmp);
  wrk->y = 0;
  wrk->x = 0;
  while (tmp != wrk->arg->prev)
    {
      print_string_mode(wrk, tmp);
      if (wrk->y == (wrk->win->h - 1))
	{
	  wrk->y = 0;
	  wrk->x += wrk->strl + 2;
	}
      else
	wrk->y += 1;
      move(wrk->y, wrk->x);
      tmp = tmp->next;
    }
  print_string_mode(wrk, tmp);
  refresh();
}

void		put_str_select(t_arg *tmp, char *prec)
{
  if (tmp->select == 1)
    {
      if (*prec)
	my_putchar(' ');
      write(1, "\"", 1);
      write(1, tmp->str, my_strlen(tmp->str));
      write(1, "\"", 1);
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

