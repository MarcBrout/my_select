/*
** my_select.h for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec  1 13:44:57 2015 marc brout
** Last update Tue Dec  1 15:09:31 2015 marc brout
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

# include <stdlib.h>
# include "my.h"

typedef	struct		s_arg
{
  char			*str;
  char			select;
  struct s_arg		*next;
  struct s_arg		*prev;
}			t_arg;

typedef struct		s_wrk
{
  t_arg			*arg;
}			t_wrk;

int add_elem_to_list(t_arg *, char *);
int create_first_elem(t_wrk *, char *);
void show_list(t_wrk *);

#endif
