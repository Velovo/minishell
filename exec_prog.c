#include "minishell.h"

int exec_prog(char *line, char **argv, char **envp)
{
	pid_t pid;

    pid = fork();
    if (pid == 0)
        execve(line, argv, envp);
    else
        wait(&pid);
}

int search_and_exec(char **tab)
{
	struct stat statbuff;
	char path[] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/mnt/c/Program Files (x86)/Common Files/Oracle/Java/javapath:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files (x86)/NVIDIA Corporation/PhysX/Common:/mnt/e/Logiciels/sshputty/:/mnt/c/Program Files/Git/cmd:/mnt/c/WINDOWS/system32:/mnt/c/WINDOWS:/mnt/c/WINDOWS/System32/Wbem:/mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/:/mnt/c/WINDOWS/System32/OpenSSH/:/mnt/e/Logiciels/Node.js/:/mnt/c/Program Files/dotnet/:/mnt/c/Program Files (x86)/Common Files/Oracle/Java/javapath:/mnt/c/Windows/system32:/mnt/c/Windows:/mnt/c/Windows/System32/Wbem:/mnt/c/Windows/System32/WindowsPowerShell/v1.0/:/mnt/c/Windows/System32/OpenSSH/:/mnt/c/Program Files (x86)/NVIDIA Corporation/PhysX/Common:/mnt/e/Logiciels/sshputty/:/mnt/c/Program Files/Git/cmd:/mnt/c/WINDOWS/system32:/mnt/c/WINDOWS:/mnt/c/WINDOWS/System32/Wbem:/mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/:/mnt/c/WINDOWS/System32/OpenSSH/:/mnt/e/Logiciels/Node.js/:/mnt/c/Program Files/dotnet/:/mnt/c/MinGW/bin:/mnt/c/Users/Velovo/AppData/Local/Programs/Microsoft VS Code/bin:/mnt/c/Users/Velovo/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/Velovo/AppData/Roaming/npm:/mnt/c/MinGW/bin:/mnt/c/Users/Velovo/AppData/Local/Programs/Microsoft VS Code/bin:/mnt/c/Users/Velovo/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/Velovo/AppData/Roaming/npm:/mnt/c/Users/Velovo/.dotnet/tools";
	char **pathed;
	int i;
	int j;
	int k;
	char *try;

	if (ft_strchr(tab[0], '/')) //check si cest un path absolu ou relatif ou si lon doit utiliser le path
	{
		if (stat(tab[0], &statbuff) == 0) //est ce que le fichier / dossier existe
		{
			if (S_ISDIR(statbuff.st_mode) == 1) //check si cest un directory
				cd(tab);
			else if (S_ISDIR(statbuff.st_mode) == 0) //ou un file
				exec_prog(tab[0], tab, NULL);
		}
		else
		{
			write(1, "mash: no such file or directory: ", ft_strlen("mash: no such file or directory: "));
			write(1, tab[0], ft_strlen(tab[0]));
			write(1, "\n", 1);
		}
	}
	else //est ce que l'executable est dans le path
	{
		pathed = ft_split(path, ':'); //parse le path en splitant a chaque : (echo $PATH)
		i = 0;
		while(pathed[i] != NULL)
		{
			try = malloc(ft_strlen(tab[0]) + ft_strlen(pathed[i]) + 2);
			j = 0;
			k = 0;
			while (pathed[i][j] != '\0')
			{
				try[k] = pathed[i][j];
				++k;
				++j;
			}
			try[k] = '/';
			++k;
			j = 0;
			while (tab[0][j] != '\0')
			{
				try[k] = tab[0][j];
				++k;
				++j;
			}
			try[k] = '\0';
			++i;

			//malloc et ctrlc ctrlv mon path + mon executable
			//printf("%s\n", try);

			if (stat(try, &statbuff) == 0) //check si ce dernier existe
			{
				exec_prog(try, tab, NULL); //virer le null et remplacer par lenv
				free(try);
				return (0);
			}
			else if (pathed[i] == NULL)	//rentre la dedans si jai test tous les path sans trouver lexcecutable
			{
				write(1, "mash: command not found: ", ft_strlen("mash: command not found: "));
				write(1, tab[0], ft_strlen(tab[0]));
				write(1, "\n", 1);
				free(try);
				return (1);
			}
			free(try);
		}
	}	
}
