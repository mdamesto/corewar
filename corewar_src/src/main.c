#include "corewar.h"

char *get_str(unsigned char *mem)
{
  const char hex[] = "0123456789abcdef ";
  char *ret;
  int i;

  ret = ft_strnew(192);
  i = 0;
  while (i < 192)
  {
    ret[i] = hex[*mem / 16];
    ret[i + 1] = hex[*mem % 16];
    ret[i + 2] = hex[16];
    i += 3;
    mem++;
  }
  return (ret);
}

void  ilight_pc(t_env *env, t_champ **champs, WINDOW *main)
{
  const char hex[] = "0123456789abcdef";
  int i;
  int j;
  char str[3];

  i = 0;
  str[2] = '\0';
  while(champs[i])
  {
    j = 0;
    while(champs[i]->process[j])
    {
      //printw("pc: %d ", champs[i]->process[j]->pc);
      str[0] = hex[env->mem[champs[i]->process[j]->pc] / 16];
      str[1] = hex[env->mem[champs[i]->process[j]->pc] % 16];
      if (j == 0)
        wattron(main, COLOR_PAIR(i + 1));
      else
        wattron(main, COLOR_PAIR(i + 5));
      mvwprintw(main , champs[i]->process[j]->pc / 64, champs[i]->process[j]->pc % 64 * 3 + 1, str);
       if (j == 0)
        wattroff(main, COLOR_PAIR(i + 1));
      else
        wattroff(main, COLOR_PAIR(i + 5));
      j++;
    }
    i++;
  }
}

void render(t_env *env)
{
  WINDOW *main;
  WINDOW *menu;
  char *str;
  int i;

  main = subwin(stdscr, 50, 193, 1, 1);
  menu = subwin(stdscr, 50, 50, 1, 196);
  wbkgd(main, COLOR_PAIR(9));
  wbkgd(menu, COLOR_PAIR(9));
  
  if (!env)
  {
    endwin();
    free(main);
    free(menu);
    exit(0);
  }

  i = 0;
  while (i < 64)
  {
    str = get_str(&(env->mem[64 * i]));
    mvwprintw(main ,i , 1, str);
    i++;
  }
  ilight_pc(env, env->champs, main);

  werase(menu);
  mvwprintw(menu ,0 , 0, "Cycle: %d", env->cycle);
  mvwprintw(menu ,1 , 0, "Cycle to die: %d", env->cycle_to_die);
  mvwprintw(menu ,2 , 0, "Lives number: %d", env->lives_nb);

  mvwprintw(menu ,12 , 0, "Player 1 waiting cycle: %d", env->champs[0]->process[0]->wait_cycle);
  if (env->champs[1])
    mvwprintw(menu ,13 , 0, "Player 2 waiting cycle: %d", env->champs[1]->process[0]->wait_cycle);
  if (env->champs[2])
    mvwprintw(menu ,14 , 0, "Player 2 waiting cycle: %d", env->champs[2]->process[0]->wait_cycle);
  if (env->champs[3])
    mvwprintw(menu ,15 , 0, "Player 2 waiting cycle: %d", env->champs[3]->process[0]->wait_cycle);

  wrefresh(main);
  wrefresh(menu);
}


int main(int argc, char **argv)
{	
  t_env *env;

	init_env();
	env = get_env(NULL);
	parse_args(argc, argv, env);
	init_process(env);
	
  if (DISPLAY)
  {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLUE);
    init_pair(6, COLOR_GREEN, COLOR_BLUE);
    init_pair(7, COLOR_YELLOW, COLOR_BLUE);
    init_pair(8, COLOR_WHITE, COLOR_BLUE);
    init_pair(9, COLOR_BLACK, COLOR_WHITE);
  }
  
  play_game(env);
  free(env);
  return 0;
}

//ASM ABORT AT THE END