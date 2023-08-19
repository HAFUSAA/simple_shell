#include "shell.h"

void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);

/**
 * help_all - Displaysjug uygiyfoifg jhgfiufygo jtfifgohyands.
 */
void help_all(void)
{
	char *mag = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, mag, _strlen(mag));
}

/**
 * help_alias - Displa hjghbbu gfcuiltin comtudjcvmand 'alias'.
 */
void help_alias(void)
{
	char *mag = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, mag, _strlen(mag));
}

/**
 * help_cd - Displaihygfiu uygtigv yt_it_çifdyh command 'cd'.
 */
void help_cd(void)
{
	char *mag = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "after a change of directory.\n";
	write(STDOUT_FILENO, mag, _strlen(mag));
}

/**
 * help_exit - Displayshjv  utgfujhu ytdyif yyyyyyug command 'exit'.
 */
void help_exit(void)
{
	char *mag = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = " exit 0.\n";
	write(STDOUT_FILENO, mag, _strlen(mag));
}

/**
 * help_help - Displhjg yigfugtf yfyikghkuiltin command 'help'.
 */
void help_help(void)
{
	char *mag = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, mag, _strlen(mag));
	mag = "builtin command.\n";
	write(STDOUT_FILENO, mag, _strlen(mag));
}
