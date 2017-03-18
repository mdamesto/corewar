#include "asm.h"

char			**init_args(void)
{
	char	**args;
	int		i;

	args = malloc(sizeof(char*) * 4);
	i = 0;
	while (i < 4)
		args[i++] = NULL;
	return (args);
}

static void		norme(char *line, int len)
{
	if (len > 2)
	{
		if (!ft_strncmp("add", line, 3))
			return (add_sub(ft_strcut_beg(line, 3), "04"));
		else if (!ft_strncmp("sub", line, 3))
			return (add_sub(ft_strcut_beg(line, 3), "05"));
		else if (!ft_strncmp("and", line, 3))
			return (or_xor_and(ft_strcut_beg(line, 3), "06"));
		else if (!ft_strncmp("xor", line, 3))
			return (or_xor_and(ft_strcut_beg(line, 3), "08"));
		else if (!ft_strncmp("ldi", line, 3))
			return (ldi_lldi(ft_strcut_beg(line, 3), "0a"));
		else if (!ft_strncmp("sti", line, 3))
			return (sti(ft_strcut_beg(line, 3), "0b"));
		else if (!ft_strncmp("lld", line, 3))
			return (ld_lld(ft_strcut_beg(line, 3), "0d"));
		else if (!ft_strncmp("aff", line, 3))
			return (aff(ft_strcut_beg(line, 3), "10"));
	}
	if (len > 1)
	{
		if (!ft_strncmp("ld", line, 2))
			return (ld_lld(ft_strcut_beg(line, 2), "02"));
		else if (!ft_strncmp("st", line, 2))
			return (st(ft_strcut_beg(line, 2), "03"));
		else if (!ft_strncmp("or", line, 2))
			return (or_xor_and(ft_strcut_beg(line, 2), "07"));
	}
}

static void		get_inst(char *line)
{
	int len;

	len = ft_strlen(line);
	if (len > 4)
	{
		if (!ft_strncmp("lfork", line, 5))
			return (live_zjump_fork_lfork(ft_strcut_beg(line, 5), "0f", 2));
	}
	if (len > 3)
	{
		if (!ft_strncmp("fork", line, 4))
			return (live_zjump_fork_lfork(ft_strcut_beg(line, 4), "0c", 2));
		else if (!ft_strncmp("live", line, 4))
			return (live_zjump_fork_lfork(ft_strcut_beg(line, 4), "01", 4));
		else if (!ft_strncmp("zjmp", line, 4))
			return (live_zjump_fork_lfork(ft_strcut_beg(line, 4), "09", 2));
		else if (!ft_strncmp("lldi", line, 4))
			return (ldi_lldi(ft_strcut_beg(line, 4), "0e"));
	}
	norme(line, len);
}

static	int		get_label(t_env *env)
{
	int		i;
	char	*label;

	i = -1;
	label = NULL;
	while (env->line[++i] && env->line[i] != LABEL_CHAR)
		;
	if (i == 0)
		ft_error(E_BD_LBL);
	if (env->line[i] == LABEL_CHAR)
		label = ft_strtrim(ft_strget(env->line, 0, i));
	if (label)
	{
		i = -1;
		while (label[++i])
			if (!ft_is_label_char(label[i]))
				return (1);
		add_label(env, label);
		env->line = ft_strcut_f(env->line, 0, ft_strlen(label) + 1);
		if (check_empty_line(env->line))
			if (!gnl())
				return (0);
		get_label(env);
	}
	return (1);
}

void			parsing_champion(t_env *env)
{
	get_name(env);
	get_comment(env);
	while (gnl() > 0)
	{
		if (get_label(env))
			get_inst(env->line);
	}
	replace_labels(env);
}
