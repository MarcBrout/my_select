/*
** moves.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Dec  9 09:30:25 2015 marc brout
** Last update Thu Dec 10 20:17:48 2015 marc brout
*/

#include "my_select.h"

void		move_right(t_wrk *wrk)
{
  int		move;

  move = wrk->win->h;
  if (wrk->pos + move < wrk->len)
    {
      wrk->cur->cursor = 0;
      while (move-- > 0)
	{
	  wrk->cur = wrk->cur->next;
	  wrk->pos += 1;
	}
      wrk->cur->cursor = 1;
    }
}

void		move_left(t_wrk *wrk)
{
  int		move;

  move = wrk->win->h;
  if (wrk->pos - move >= 0)
    {
      wrk->cur->cursor = 0;
      while (move-- > 0)
	{
	  wrk->cur = wrk->cur->prev;
	  wrk->pos -= 1;
	}
      wrk->cur->cursor = 1;
    }
}

void		move_next(t_wrk *wrk)
{
  wrk->cur->cursor = 0;
  wrk->cur = wrk->cur->next;
  wrk->cur->cursor = 1;
  wrk->pos += (wrk->pos < wrk->len) ? 1 : -wrk->len;
}

void		move_prev(t_wrk *wrk)
{
  wrk->cur->cursor = 0;
  wrk->cur = wrk->cur->prev;
  wrk->cur->cursor = 1;
  wrk->pos += (wrk->pos > 0) ? -1 : wrk->len;
}

void		move_key(t_wrk *wrk, int key)
{
  int		i;

  i = -1;
  while (++i < 10 && wrk->keytab[i] != key);
  if (i < 10)
    wrk->pfunc[i](wrk);
  clear();
}
