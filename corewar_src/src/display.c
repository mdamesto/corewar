#include "corewar.h"

char *empty_line()
{
    int i;
    int sp;
    char *ret;

    i = -1;
    sp = 0;
    ret = ft_memalloc(192);
    while (++i < 191)
    {
        if (sp++ != 2)
            ret[i] = '0';
        else
        {
            ret[i] = ' ';
            sp = 0;
        }
    }
    return (ret);
}

void   my_init_color()
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_WHITE);
    init_pair(2, COLOR_GREEN, COLOR_WHITE);
    init_pair(3, COLOR_YELLOW, COLOR_WHITE);
    init_pair(4, COLOR_WHITE, COLOR_WHITE);
    init_pair(5, COLOR_RED, COLOR_BLUE);
    init_pair(6, COLOR_GREEN, COLOR_BLUE);
    init_pair(7, COLOR_YELLOW, COLOR_BLUE);
    init_pair(8, COLOR_WHITE, COLOR_BLUE);
    init_pair(9, COLOR_BLACK, COLOR_WHITE);
}

void init_display(t_env *env)
{
    WINDOW *main;
    WINDOW *menu;
    int i;
    char *str;

    initscr();
    cbreak();
    noecho();
    //nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    my_init_color();
    
    main = subwin(stdscr, 50, 193, 1, 1);
    menu = subwin(stdscr, 50, 40, 1, 196);
    wbkgd(main, COLOR_PAIR(9));
    wbkgd(menu, COLOR_PAIR(9));
    env->w_main = main;
    env->w_menu = menu;

    i = -1;
    str = empty_line();
    while (++i < 64)
        mvwprintw(main ,i , 1, str);
    free(str);
}

char *format_to_print(char *in, int start, int len)
{
  const char hex[] = "0123456789abcdef ";
  char *ret;
  int i;
  int j;
  unsigned char *str;

  str = (unsigned char*)in;
  ret = ft_strnew(192);

  i = 0;
  j = start;
  len = start + len;

  while (j < len)
  {
    ret[i] = hex[str[j] / 16];
    ret[i + 1] = hex[str[j] % 16];
    ret[i + 2] = hex[16];
    i += 3;
    j++;
  }
  return (ret);
}

void    print_on_mem(char *str, int start, int len, int color)
{
    t_env *env;
    int line;
    char *to_print;
    int count;

    env = get_env(NULL);
    line = start / 64;
    start = start % 64;
    count = 0;

    wattron(env->w_main, COLOR_PAIR(color));
    to_print = format_to_print(str, count, 64 - start);
    mvwprintw(env->w_main ,line++, start + 1, to_print);
    len -= 64 - start;
    count += 64 - start;
    while (len > 64)
    {
        to_print = format_to_print(str, count, 64);
        mvwprintw(env->w_main ,line++ , 1, to_print);
        count += 64;
        len -= 64;
    }
    to_print = format_to_print(str, count, len);
    mvwprintw(env->w_main ,line , 1, to_print);
    wattroff(env->w_main, COLOR_PAIR(color));
    wrefresh(env->w_main);
    getch(); //REMOVE
}