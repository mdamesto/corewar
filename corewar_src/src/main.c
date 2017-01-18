#include "corewar.h"

/*void	place_champs()
{
	t_env *env;

	env = get_env(NULL);

}*/

int main(int argc, char **argv)
{
	t_env *env;

	env = get_env(NULL);
	init_env();
	parse_args(argc, argv);
	//place_champ();
	return 0;
}