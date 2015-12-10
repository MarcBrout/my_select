/*
** string_styles.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Dec  9 09:26:56 2015 marc brout
** Last update Wed Dec  9 20:52:24 2015 marc brout
*/

#include "my_select.h"

void		my_put_stch_underline(t_wrk *wrk, char *str)
{
  int		i;
  int		diff;

  diff = wrk->win->w - wrk->x;
  i = -1;
  while (str[++i] && diff-- > 0)
    addch(str[i] | A_UNDERLINE);
}

void		my_put_stch_bgcolor(t_wrk *wrk, char *str)
{
  int		i;
  int		diff;

  diff = wrk->win->w - wrk->x;
  i = -1;
  while (str[++i] && diff-- > 0)
    addch(str[i] | A_REVERSE);
}

void		my_put_stch_both(t_wrk *wrk, char *str)
{
  int		i;
  int		diff;

  diff = wrk->win->w - wrk->x;
  i = -1;
  while (str[++i] && diff-- > 0)
    addch(str[i] | A_UNDERLINE | A_REVERSE);
}

void		my_put_stnorm(t_wrk *wrk, char *str)
{
  int		i;
  int		diff;

  diff = wrk->win->w - wrk->x;
  i = -1;
  while (str[++i] && diff-- > 0)
    addch(str[i]);
}

void		print_string_mode(t_wrk *wrk, t_arg *arg)
{
  if (arg->cursor && !arg->select)
    my_put_stch_underline(wrk, arg->str);
  else if (!arg->cursor && arg->select)
    my_put_stch_bgcolor(wrk, arg->str);
  else if (arg->cursor && arg->select)
    my_put_stch_both(wrk, arg->str);
  else
    my_put_stnorm(wrk, arg->str);
}
