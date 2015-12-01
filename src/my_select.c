/*
** select.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec  1 13:40:18 2015 marc brout
** Last update Tue Dec  1 15:14:19 2015 marc brout
*/

#include "../include/my_select.h"

int		add_elem_to_list(t_arg *arg, char *str)
{
  t_arg		*elem;

  if (str == NULL)
    return (1);
  if ((elem = malloc(sizeof(t_arg))) == NULL)
    return (2);
  elem->str = str;
  elem->select = 0;
  elem->next = arg;
  elem->prev = arg->prev;
  arg->prev->next = elem;
  arg->prev = elem;
}

int		create_first_elem(t_wrk *wrk, char *str)
{
  t_arg		*elem;

  if (str == NULL)
    return (1);
  if ((elem = malloc(sizeof(t_arg))) == NULL)
    return (2);
  elem->str = str;
  elem->select = 0;
  elem->next = elem;
  elem->prev = elem;
  wrk->arg = elem;
  return (0);
}

void		show_list(t_wrk *wrk)
{
  t_arg		*tmp;

  tmp = wrk->arg;
  while ((tmp = tmp->next) != wrk->arg)
    my_printf("%s\n", tmp->str);
}

int		main(int ac, char **av)
{
  t_wrk		wrk;
  int		i;

  if (ac < 2)
    return (1);
  create_first_elem(&wrk, av[1]);
  i = 1;
  while (av[++i])
    add_elem_to_list(wrk.arg, av[i]);
  show_list(&wrk);
}
