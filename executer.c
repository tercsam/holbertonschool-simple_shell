#include "main.h"
/**
 *execute_command - execute a command given in the shell
 *@commande : the command given
 *@args : array of strings
 *Return: 1 if success and ask for the next command
 */


int execute_command(char *commande, char *args[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(commande, args) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error forking");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
