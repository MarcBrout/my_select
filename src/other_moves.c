/*
** other_moves.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Dec 10 18:54:06 2015 marc brout
** Last update Sun Dec 13 16:16:56 2015 marc brout
*/

#include "my_select.h"

void		select_all(t_wrk *wrk)
{
  t_arg		*tmp;

  tmp = wrk->arg;
  while ((tmp = tmp->next) && tmp != wrk->arg)
    tmp->select = (wrk->selecta) ? 0 : 1;
  tmp->select = (wrk->selecta) ? 0 : 1;
  wrk->selecta = (wrk->selecta) ? 0 : 1;
}

void		select_inv(t_wrk *wrk)
{
  t_arg		*tmp;

  tmp = wrk->arg;
  while ((tmp = tmp->next) && tmp != wrk->arg)
    tmp->select = (tmp->select) ? 0 : 1;
  tmp->select = (tmp->select) ? 0 : 1;
}

void		del_select(t_wrk *wrk)
{
  t_arg		*tmp;

  wrk->cur->cursor = 0;
  tmp = wrk->arg;
  while ((tmp = tmp->next) && tmp != wrk->arg)
    if (tmp->select == 1)
      tmp = delete_node_sel(wrk, tmp);
  if (tmp->select == 1)
    delete_node_sel(wrk, tmp);
  wrk->cur = wrk->arg;
  wrk->cur->cursor = 1;
}

void		free_list(t_wrk *wrk)
{
  t_arg		*tmp;

  if (wrk->len)
    {
      tmp = wrk->arg->next;
      while ((tmp = tmp->next) != wrk->arg)
	free(tmp->prev);
      if (tmp->prev != wrk->arg)
	free(tmp->prev);
      free(wrk->arg);
    }
  free(wrk->keytab);
  free(wrk->pfunc);    
}
