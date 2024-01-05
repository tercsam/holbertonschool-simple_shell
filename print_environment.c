#include "main.h"
/**
 * print_environment - Prints the environment variables to the standard output.
 * @env : An array of strings representing the environment variables.
 * Return: 1 if success
 */

int print_environment(char **env)
{
	char **env_var = env;

	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
	return (1);
}
