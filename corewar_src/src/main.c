#include "corewar.h"

int main(int argc, char **argv)
{
	t_env *env;

	init_env();
	env = get_env(NULL);
	parse_args(argc, argv, env);
	init_process(env);
	play_game(env);

	return 0;
}

//ASM ABORT AT THE END