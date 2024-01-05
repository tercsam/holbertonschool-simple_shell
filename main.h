#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

void display_prompt(void);
ssize_t read_input(char **line, size_t *len);
void remove_newline(char *str);
void execute_command(char *command);

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#endif /* MAIN_H */

