/*
** my_putstr_err.c for my_ls
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sat Nov 28 22:22:04 2015 marc brout
** Last update Tue Dec  1 13:28:47 2015 marc brout
*/

void		my_putchar_err(char c)
{
  write(2, &c, 1);
}

void		my_putstr_err(char *str)
{
  write(2, str, my_strlen(str));
}
