#include "main.h"

/**
 * main - Fonction principale du programme
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t len = 0;
	char *token;
	char *command;
	char *args[10];
	int i;

	while (1)
	{
		printf("($) ");
		if (getline(&buffer, &len, stdin) == -1)
		{
			free(buffer);
			perror("getline failed");
			exit(EXIT_FAILURE);
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		
		token = strtok(buffer, " ");
		command = token;
		i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		execute_command(command, args);
	}

	return (0);
}

/**
 * execute_command - Exécute une commande en utilisant fork et exec
 * @command: La commande à exécuter
 * @args: Tableau d'arguments de la commande
 *
 */
void execute_command(char *command, char *args[])
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execvp(command, args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

