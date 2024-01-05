#include "main.h"
/**
 *display_prompt - affiche le nom de l'inviter du shell
 *
 * Return: 0 if error and 1 if success
 */

int display_prompt(void)
{
	if (write(STDOUT_FILENO, "$ ", 2) == -1)
	{
		return (0);
	}
	return (1);
}
