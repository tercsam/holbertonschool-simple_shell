#include "main.h"

int main(void) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1) {
		display_prompt();
		read = read_input(&line, &len);

		if (read == -1) {
			printf("\n");
			break;
		}

		remove_newline(line);

		pid_t pid = fork();

		if (pid == -1) {
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}

		if (pid == 0) {
			execute_command(line);
			exit(EXIT_FAILURE);
		} else {
			wait(NULL);
		}
	}

	free(line);
	exit(EXIT_SUCCESS);
}


