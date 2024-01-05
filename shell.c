#include "main.h"
/**
 * main - Entry point for the simple shell program
 * @argc : The number of command-line arguments.
 * @argv : An array of strings representing the command-line arguments.
 * @envp : An array of strings representing the environment variables.
 *Return: EXIT_SUCCESS upon successful execution, EXIT_FAILURE otherwise.
 */

int main(int argc __attribute__((unused)),
		char *argv[] __attribute__((unused)),
		char *envp[])
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS], *token;
	char *full_path;
	int arg_count;

	while (display_prompt() && fgets(command, sizeof(command), stdin) != NULL)
	{
		command[strcspn(command, "\n")] = '\0';
		if (strlen(command) == 0)
			continue;
		arg_count = 0;
		token = strtok(command, " ");

		while (token != NULL && arg_count < MAX_ARGS - 1)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		if (args[0] != NULL && strcmp(args[0], "exit") == 0)
		{
			printf("Exiting shell...\n");
			return (EXIT_SUCCESS);
		} else if (args[0] != NULL && strcmp(args[0], "env") == 0)
		{
			if (!print_environment(envp))
				return (EXIT_FAILURE);
			continue;
		}
		full_path = find_executable(args[0]);
		if (args[0] != NULL && !full_path)
		{
			printf("Command not found: %s\n", args[0]);
			continue;
		}
		if (args[0] != NULL && !execute_command(full_path, args))
		{
			return (EXIT_FAILURE);
		}
	}	
	return (EXIT_SUCCESS);
}
