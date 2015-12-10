/*
** inits.c for my_select
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Dec 10 20:18:35 2015 marc brout
** Last update Thu Dec 10 20:20:49 2015 marc brout
*/

#include "my_select.h"

void		init_keytab(t_wrk *wrk)
{
  wrk->keytab[0] = KEY_DOWN;
  wrk->keytab[1] = KEY_LEFT;
  wrk->keytab[2] = KEY_RIGHT;
  wrk->keytab[3] = KEY_UP;
  wrk->keytab[4] = MY_KEY_SPACE;
  wrk->keytab[5] = KEY_DC;
  wrk->keytab[6] = KEY_BACKSPACE;
  wrk->keytab[7] = MY_CTRL_A;
  wrk->keytab[8] = MY_CTRL_W;
  wrk->keytab[9] = MY_CTRL_B;
}

void		init_pfunc(t_wrk *wrk)
{
  wrk->pfunc[0] = &move_next;
  wrk->pfunc[1] = &move_left;
  wrk->pfunc[2] = &move_right;
  wrk->pfunc[3] = &move_prev;
  wrk->pfunc[4] = &select_it;
  wrk->pfunc[5] = &delete_node;
  wrk->pfunc[6] = &delete_node;
  wrk->pfunc[7] = &select_all;
  wrk->pfunc[8] = &select_inv;
  wrk->pfunc[9] = &del_select;
}

char		init_tabs(t_wrk *wrk)
{
  if (((wrk->keytab = malloc(sizeof(int) * 11)) == NULL) ||
      ((wrk->pfunc = malloc(8 * 11)) == NULL))
    return (1);
  init_keytab(wrk);
  init_pfunc(wrk);
  return (0);
}

char		init_window(t_wrk *wrk)
{
  if ((wrk->screen = newterm(NULL, stderr, stdin)) == NULL)
    return (1);
  set_term(wrk->screen);
  wrk->selecta = 0;
  curs_set(0);
  keypad(stdscr, TRUE);
  wrk->arg->cursor = 1;
  wrk->cur = wrk->arg;
  wrk->x = 0;
  wrk->y = 0;
  wrk->pos = 0;
  return (0);
}
