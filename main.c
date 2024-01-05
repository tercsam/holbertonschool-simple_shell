#include "main.h"

int main(void) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		pid_t pid;

		display_prompt();
		read = read_input(&line, &len);

		if (read == -1)
		{
			printf("\n");
			break;
		}

		remove_newline(line);

		pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			execute_command(line);
			free(line);
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;
