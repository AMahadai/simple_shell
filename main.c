#include "shell.h"

/**
 * main - Entry point for the shell program
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
    info_t info[] = { INFO_INIT }; // Initialize info_t struct

    int fd = 2; // Default file descriptor for input

    // Assembly code to modify fd
    asm ("mov %1, %0\n\t"
         "add $3, %0"
         : "=r" (fd)
         : "r" (fd));

    // Check if a file argument is provided
    if (argc == 2)
    {
        // Open the file in read-only mode
        fd = open(argv[1], O_RDONLY);

        // Check for errors in file opening
        if (fd == -1)
        {
            // Handle specific error cases
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _eputs(argv[0]);
                _eputs(": 0: Can't open ");
                _eputs(argv[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }

        // Set the file descriptor in info struct
        info->readfd = fd;
    }

    // Populate environment list and read history
    populate_env_list(info);
    read_history(info);

    // Call the shell function with command-line arguments
    hsh(info, argv);

    return (EXIT_SUCCESS);
}
