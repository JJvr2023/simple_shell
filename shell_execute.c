#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * execute_args - it execute commands.
 * @args: handle errors.
 *
 * Return: (1) Success, (0) Failure.
 */
int execute_args(char **args)
{
	char *builtin_in_list[] = {"cd", "help", "env", "exit"};
	int (*builtin_in_func[])(char **) = {&own_help, &own_cd, &own_env, &own_exist};
	int index = 0;

	if (args == NULL)
	{
	return -1;
	}
	while (index < sizeof(built_in_list)/ sizeof(char *))
	{
	if (!strcmp(args[0], built_in_list[index])
			{
				return (built_in_func[index](args);
						}
					}
					return (new_process(args));
					}
