#include "../head/minishell.h"

int env_len(char **env)
{
	int i = 0;

	while (env[i] != NULL)
		++i;
	return (i);
}

char **new_env(char **envp)
{
	char **tenv;
	int i;

	tenv = malloc(env_len(envp) * sizeof(char*)); //proteger le malloc
	//printf("%d\n", env_len(envp));
	i = 0;
	while (envp[i] != NULL)
	{
		tenv[i] = malloc(ft_strlen(envp[i]) * sizeof(char));
		ft_strlcpy(tenv[i], envp[i], ft_strlen(envp[i]));
		++i;
	}
	tenv[i] = NULL;
	return (tenv);
}