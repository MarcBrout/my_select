/*
** results.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Dec  9 09:37:51 2015 marc brout
** Last update Wed Dec  9 15:03:20 2015 marc brout
*/

#include "my_select.h"

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

