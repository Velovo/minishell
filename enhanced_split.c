#include "minishell.h"

void	*free_arr(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (NULL);
}

static int	count_split(const char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		// printf("ret = %d  str = %s\n", ret, &str[i]);
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			--i;
		}
		else if (str[i] == '\"')
		{
			++ret;
			++i;
			while (str[i] != '\"' && str[i] != '\0')
			{
				if (str[i] == '\\')
					++i;
				++i;
			}
			if (str[i + 1] != ' ' && str[i + 1] != '\0')
				--ret;
		}
		else if (str[i] == '\'')
		{
			++ret;
			++i;
			while (str[i] != '\'' && str[i] != '\0')
			{
				if (str[i] == '\\' && str[i + 1] != '\'')
					++i;
				++i;
			}
			if (str[i + 1] != ' ' && str[i + 1] != '\0')
				--ret;
		}
		else
		{
			++ret;
			while (str[i] != ' ' && str[i] != '\0')
				++i;
			--i;
		}
		i++;
	}
	return (ret);
}

static int	count_words(const char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] == ' ')
		++i;
	while (str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] == '\"')
		{
			++i;
			while (str[i] != '\"' && str[i] != '\0')
			{
				if (str[i] == '\\' && str[i + 1] == '\"')
					++i;
				++i;
				++ret;
			}
		}
		else if (str[i] == '\'')
		{
			++i;
			while (str[i] != '\'' && str[i] != '\0')
			{
				++i;
				++ret;
			}
		}
		else if (str[i] == '\\')
		{
			++i;
			++ret;
		}
		else
			++ret;
		++i;
	}
	return (ret);
}

char *fill_word(const char *str)
{
	int i;
	char *word;
	int dep;

	if (!(word = malloc(((count_words(str) + 1) * sizeof(char)))))
		return (NULL);
	ft_memset(word, 0, count_words(str) + 1);
	i = 0;
	dep = 0;
	while (str[i] == ' ')
		++i;
	while (str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] == '\"')
		{
			++i;
			while (str[i] != '\"' && str[i] != '\0')
			{
				if (str[i] == '\\' && str[i + 1] == '\"')
					++i;
				word[dep] = str[i];
				++dep;
				++i;
			}
		}
		else if (str[i] == '\'')
		{
			++i;
			while (str[i] != '\'' && str[i] != '\0')
			{
				word[dep] = str[i];
				++dep;
				++i;
			}
		}
		else if (str[i] == '\\')
		{
			++i;
			word[dep] = str[i];
			++dep;
		}
		else
		{
			word[dep] = str[i];
			++dep;
		}
		++i;
	}
	word[dep] = '\0';
	return (word);
}

int advance(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		++i;
	while (str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] == '\"')
		{
			++i;
			while (str[i] != '\"' && str[i] != '\0')
			{
				if (str[i] == '\\' && str[i + 1] == '\"')
					++i;
				++i;
			}
		}
		else if (str[i] == '\'')
		{
			++i;
			while (str[i] != '\'' && str[i] != '\0')
				++i;
		}
		else if (str[i] == '\\')
			++i;
		++i;
	}
	return (i);
}

char		**ft_enhanced_split(char const *str)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	// printf("str init = %s\n", str);
	//printf("split nbr = %d\n", count_split(str));
	if (!(tab = malloc((count_split(str) + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_split(str))
	{
		// printf("count = %d\n", count_words(&str[i]));
		k = 0;
	 	tab[j] = fill_word(&str[i]);
		j++;
		i = i + advance(&str[i]);
		//rajouter des trucs ici pour passer au prochain mots (sarreter au prochain espace pas dans des quotes)
	}
	tab[j] = NULL;
	i = 0;
	// while(tab[i] != NULL)
	//   	printf("finale: %s\n", tab[i++]);
	// free_arr(tab, j);
	return (tab);
}
