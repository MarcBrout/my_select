/*
** moves.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Dec  9 09:30:25 2015 marc brout
** Last update Wed Dec  9 20:13:18 2015 marc brout
*/

#include "my_select.h"

void		select_it(t_wrk *wrk)
{
  wrk->cur->select = (wrk->cur->select) ? 0 : 1;
  move_next(wrk);
}

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
  if (key == KEY_DOWN)
    move_next(wrk);
  if (key == KEY_LEFT)
    move_left(wrk);
  if (key == KEY_RIGHT)
    move_right(wrk);
  if (key == KEY_UP)
    move_prev(wrk);
  if (key == MY_KEY_SPACE)
    select_it(wrk);
  if (key == KEY_DC || key == MY_KEY_BSPACE)
    delete_node(wrk);
  clear();
}
