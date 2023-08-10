#include "shell.h"

/**
* _myexit - exits the shell
* @info: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: exits with a given exit status
* (0) if info.argv[0] != &quot;exit&quot;
*/
int _myexit(info_t *info)
{

int exitcheck;
if (info->argv[1]) /* If there is an exit arguement */
{
exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
exit(info->err_num);
}
return (0);
}

/**
* _mycd - changes the current directory of the process
* @info: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: Always 0
*/
int _mycd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_ret;
s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >&gt;getcwd failure emsg here&lt;&lt;\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
chdir_ret = /* TODO: what should this be? */
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");

else
chdir_ret = chdir(dir);

}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);

_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /* TODO: what should this be? */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");

}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD=", _getenv(info, "PWD="));
_setenv(info, "PWD=", getcwd(buffer, 1024));
}
return (0);
}

/**
* _myhelp - prints a help message for the shell
* @info: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: Always 0
*/
int _myhelp(info_t *info)
{
char **arg_array;
arg_array = info->argv;
_puts("Shell help\n");
_puts("The following commands are supported:\n");
_puts("  exit - Exits the shell\n");
_puts("  cd - Changes the current directory\n");
_puts("  help - Prints this help message\n");
return (0);
}
