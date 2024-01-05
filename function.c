#include <main.h>

void display_prompt(void) {
	printf("simple_shell> ");
}

ssize_t read_input(char **line, size_t *len) {
	return getline(line, len, stdin);
}

void remove_newline(char *str) {
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}

void execute_command(char *command) {
	if (execve(command, NULL, NULL) == -1) {
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
}
