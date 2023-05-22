#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int my_execvp(const char *file, char *const argv[]) {
    /* Get the value of the PATH environment variable */
    char *path, *dir;
    const char *delim;

    path  = getenv("PATH");
    if (path == NULL) {
        perror( "Error: PATH environment variable not found\n");
        return (-1);
    }

    /* Tokenize the PATH variable to get individual directories*/
    delim = ":";
    dir = strtok(path, delim);

    /* Iterate over each directory in PATH */
    while (dir != NULL) {
        /* Create the full path to the executable file */
        size_t path_len = _strlen(dir) + _strlen(file) + 2;
        char *exec_path = (char *)malloc(path_len);
        if (exec_path == NULL) {
            perror("Error: Memory allocation failed");
            return -1;
        }
	_strcpy(exec_path, dir);
	strcat(exec_path, "/");
	strcat(exec_path, file);
        /*snprintf(exec_path, path_len, "%s/%s", dir, file);*/

        /* Execute the command using execve()*/
        execve(exec_path, argv, environ);

        /* Clean up and move to the next directory */
        free(exec_path);
        dir = strtok(NULL, delim);
    }

    /* If execution reaches here, the command was not found in any directory */
    perror( "Error: Command not found: %s\n");
    return -1;
}

