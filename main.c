#include "shell.h"

/**
 * main - this is the entry point of the program
 * @ac: the number of command line arguments
 * @av: array of strings containing
 * command line arguments
 *
 * Return: 0 success, 1 error
 */
int main(int argc, char **argv)
{
    info_t info[] = { INFO_INIT };
    int fd = 2; /* standard error (2) if not file provided */

    fd = computeNewFileDescriptor(fd);

    if (argc == 2)
    {
        fd = openFile(argv[1]);
        if (fd == -1)
        {
            handleFileOpenError(argv[0], argv[1]);
            return EXIT_FAILURE; /* return failure if not able to open file */
        }
        info->readfd = fd; /* read file descriptor in info struct */
    }

    populateEnvList(info); /* populate environment infor struct */
    readHistory(info); /* read history from file */
    executeShell(info, argv); /* function with info struct and command line arguments */
    return EXIT_SUCCESS; /* Return success */
}
