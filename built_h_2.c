#include "shell.h"

void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);

/**
 * help_env - Displaysknhn hgggggguy bhgoguiltin command 'env'.
 */
void help_env(void)
{
	char *mag = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, mag, _strlen(mag));
}

/**
 * help_setenv - Dispigjopkjh jhhhhhfg l jlfdmand 'setenv'.
 */
void help_setenv(void)
{
	char *mag = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, mag, _strlen(mag));
}

/**
 * help_unsetenv - Displays infooiughn, pijht ijphgthj command
 * 'unsetenv'.
 */
void help_unsetenv(void)
{
	char *mag = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "message to stderr.\n";
	write(STDOUT_FILENO, mag, _strlen(mag));
}
