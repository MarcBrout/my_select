/*
** lists.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Dec  9 09:23:40 2015 marc brout
** Last update Thu Dec 10 17:51:07 2015 marc brout
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
  elem->search = 0;
  elem->select = 0;
  elem->next = arg;
  elem->prev = arg->prev;
  arg->prev->next = elem;
  arg->prev = elem;
  wrk->len += 1;
  wrk->strl = (my_strlen(str) > wrk->strl) ? my_strlen(str) : wrk->strl;
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
  elem->search = 0;
  elem->next = elem;
  elem->prev = elem;
  wrk->arg = elem;
  wrk->strl = my_strlen(str);
  wrk->len = 1;
  return (0);
}

t_arg		*delete_node_sel(t_wrk *wrk, t_arg *arg)
{
  t_arg		*tmp;

  tmp = arg->prev;
  wrk->cur = arg;
  delete_node(wrk);
  wrk->cur->cursor = 0;
  return (tmp);
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
