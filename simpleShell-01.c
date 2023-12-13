#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
 * main - Fonction principale du programme
 *
 * Description: Cette fonction est le point d'entrée du programme.
 * Elle gère la boucle principale d'interaction avec l'utilisateur.
 *
 * Return: 0 en cas de succès, sinon une valeur d'erreur.
 */
int main(void)
{
	char *buffer = NULL;
	size_t len = 0;

	while (1)
	{
		printf("($) ");
		if (getline(&buffer, &len, stdin) == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		execute_command(buffer);
	}

	free(buffer);

	return (0);
}

/**
 * execute_command - Exécute une commande en utilisant fork et exec
 * @command: La commande à exécuter
 *
 * Description: Cette fonction crée un processus fils pour exécuter
 * la commande spécifiée en utilisant exec.
 */
void execute_command(char *command)
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
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

