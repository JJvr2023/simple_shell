#include "shell.h"

/**
 * is_cmd - examine if file is executable
 * @info: infomation struct
 * @path: path file
 *
 * Return: if file is excutable it return 1, 0 is or else
 */
int is_cmd(info_t *info, char *path)
{
    struct stat file_stat;

    (void)info;

    if (!path || stat(path, &file_stat) != 0) {
        return 0;
    }

    if (S_ISREG(file_stat.st_mode) && (file_stat.st_mode & S_IXUSR)) {
        return 1;
    }

    return 0;
}

/**
 * duplicate_substring - makes duplicate substring from string
 * @string: the string
 * @start: begin index of substring
 * @stop: substring stopped index 
 *
 * Return: pointer new buffer  
 */
char *duplicate_substring(char *string, int start, int stop)
{
    static char buf[1024];
    int buf = 0;

    for (int i = start; i < stop; i++) {
        if (string[i] != ':') {
            buf[buf++] = string[i];
        }
    }

    buf[buf] = '\0';
    return buf;
}

/**
 * find_path - examine this command in the PATH environment variable
 * @info: info struct
 * @path_string: path string
 * @cmd: the command to examine
 *
 * Return: full path of the command if found, NULL or else
 */
char *find_path(info_t *info, char *path_string, char *cmd)
{
    int path_index = 0, curr_pos = 0;
    char *path;

    if (!pathstr) {
        return NULL;
    }

    if ((_strlen(cmd) > 2) && starts_with(cmd, "./")) {
        if (is_cmd(info, cmd)) {
            return cmd;
        }
    }

    while (1) {
        if (!path_str[path_index] || path_str[path_index] == ':') {
            path = duplicate_substring(path_str, curr_pos, path_index);

            if (!*path) {
                _strcat(path, cmd);
            } else {
                _strcat(path, "/");
                _strcat(path, cmd);
            }

            if (is_cmd(info, path)) {
                return path;
            }

            if (!path_string[path_index]) {
                break;
            }

            curr_pos = path_index;
        }
        path_index++;
    }

    return NULL;
}
