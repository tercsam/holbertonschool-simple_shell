#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10
#define MAX_PATH_LENGTH 100

int executer_commande(char *commande);
int execute_command(char *command, char *args[]);
char *find_executable(char *command);
int print_environment(char **env);
int display_prompt(void);
/**
 * main - Entry point for the simple shell program
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @envp: An array of strings representing the environment variables.
 * Return: EXIT_SUCCESS upon successful execution, EXIT_FAILURE otherwise.
 */
int main(int argc __attribute__((unused)),
		char *argv[] __attribute__((unused)),
		char *envp[]);


#endif
