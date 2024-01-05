#include "main.h"
/**
 * find_executable - Finds the full path of an executable in the system's PATH.
 *
 * @command: A string representing the command given by the user.
 * @full_path: A buffer to store the full path of the executable.
 *
 * This function searches for the specified command in the directories listed
 * in the PATH environment variable. If the command is found and is executable,
 * the full path is stored in the provided buffer.
 *
 * Return: 1 if the executable is found, 0 otherwise.
 */

char *find_executable(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char *full_path;

	if (strchr(command, '/') != NULL)
	{
		return (command);
	}
	while (token != NULL)
	{
		full_path = malloc(sizeof(char *) * (strlen(token) + strlen(command) + 2));
		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
