#include "main.h"

void display_prompt(void) 
{
	printf("$ ");
}

size_t read_input(char **line, size_t *len)
{
	return getline(line, len, stdin);
}

void remove_newline(char *str) 
{
	size_t len;
	if (str != NULL) 
	{
		len = strlen(str);
		if(len > 0 && str[len - 1] == '\n')
		{
			str[len - 1] = '\0';
		}
	}
}

void execute_command(char *command)
{	
	char *args[2];
	args[0] = command;
	args[1] = NULL;


	if (execve(command, args, NULL) == -1)
	{
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
}

