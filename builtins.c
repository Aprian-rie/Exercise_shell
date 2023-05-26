#include "main.h"
/** builtin commands*/
char *builtin_str[] = {
        "cd",
        "exit"
};
int (*builtin_func[]) (char **) = {
        &our_cd,
        &our_exit
};
int num_builtins()
{
        return sizeof(builtin_str) / sizeof(char *);
}

/**
 * our_exit - exit builtin
 */
int our_exit(char **args)
{
	(void) args;
	exit(0);
}

/**
 * our_cd - cd builtin
 */
int our_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("Missing argument\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error: cd");
		}
	}
	return (1);
}
