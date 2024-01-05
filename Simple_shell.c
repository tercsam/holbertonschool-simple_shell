#include "main.h"

/**
 * main - Fonction principale du programme
 *
 * Return: Always 0
 */
int main(void)
{
	char *ligneSaisieUser = NULL;
	size_t tailleLigneSaisie = 0;
	char *mot;
	char *nomCommande;
	char *arguments[10];
	int i;
	char **env;

	while (1)
	{
		printf("$ ");
		if (getline(&ligneSaisieUser, &tailleLigneSaisie, stdin) == -1)
		{
			free(ligneSaisieUser);
			perror("getline failed");
			exit(EXIT_FAILURE);
		}

		ligneSaisieUser[strcspn(ligneSaisieUser, "\n")] = '\0';

		if (strcmp(ligneSaisieUser, "exit") == 0)
		{
			free(ligneSaisieUser);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(ligneSaisieUser, "env") == 0)
		{
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			continue;
		}

		mot = strtok(ligneSaisieUser, " ");
		nomCommande = mot;
		i = 0;

		while (mot != NULL)
		{
			arguments[i++] = mot;
			mot = strtok(NULL, " ");
		}
		arguments[i] = NULL;

		execute_command(nomCommande, arguments);
	}

	return 0;
}

/**
 * execute_command - Exécute une commande en utilisant fork et exec
 * @command: La commande à exécuter
 * @args: Tableau d'arguments de la commande
 *
 */
void execute_command(char *nomCommande, char *arguments[])
{
	pid_t idtPIDenfant;
	char *path = getenv("PATH");
	char *token, *directory;
	int command_exists = 0;

	token = strtok(path, ":");

	while (token != NULL)
	{
		directory = malloc(strlen(token) + strlen("/") + strlen(nomCommande) + 1);
		strcpy(directory, token);
		strcat(directory, "/");
		strcat(directory, nomCommande);

		if (access(directory, X_OK) == 0)
		{
			command_exists = 1;
			break;
		}

		free(directory);
		token = strtok(NULL, ":");
	}

	if (!command_exists)
	{
		fprintf(stderr, "Command not found: %s\n", nomCommande);
		return;
	}

	idtPIDenfant = fork();

	if (idtPIDenfant == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (idtPIDenfant == 0)
	{
		if (execvp(directory, arguments) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}

	free(directory);
}
