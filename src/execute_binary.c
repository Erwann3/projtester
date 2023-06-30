/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** execute_binary.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "../include/my.h"

char *find_binary_name(char *name)
{
    char *binary_path = NULL;
    size_t path_len = 0;
    char *result = NULL;

    binary_path = find_binary_in_path(name);
    if (binary_path == NULL)
        binary_path = find_binary_in_folder(name);
    if (binary_path == NULL)
        return NULL;
    path_len = strlen(binary_path);
    result = malloc(path_len + 1);
    if (result == NULL)
        return NULL;
    strcpy(result, binary_path);
    return result;
}

void child_process_exec(int *pipefd, char *binary,
    char **args, char *input_file)
{
    int arg_count = 0;
    char **new_args = NULL;
    int input_fd = 0;

    while (args[arg_count] != NULL)
        ++arg_count;
    new_args = malloc((arg_count + 2) * sizeof(char *));
    new_args[0] = binary;
    for (int i = 0; i <= arg_count; ++i)
        new_args[i + 1] = args[i];
    input_fd = open(input_file, O_RDONLY);
    if (input_fd != -1) {
        dup2(input_fd, STDIN_FILENO);
        close(input_fd);
        close(pipefd[0]);
    }
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    execv(binary, new_args);
    free(new_args);
}

char *read_from_pipe(int *pipefd)
{
    char buffer[4096];
    ssize_t bytes_read = 0;
    size_t total_size = 0;
    char *output = NULL;
    char *temp_ptr = NULL;

    close(pipefd[1]);
    while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0) {
        temp_ptr = realloc(output, total_size + bytes_read + 1);
        output = temp_ptr;
        memcpy(output + total_size, buffer, bytes_read);
        total_size += bytes_read;
    }
    if (output != NULL)
        output[total_size] = 0;
    close(pipefd[0]);
    return output;
}

int get_exit_status(pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    return -1;
}

int execute_bft(char *binary, char **args,
    char **output, char *input_file)
{
    int pipefd[2];
    pid_t pid;
    int exit_status = 0;

    if (pipe(pipefd) == -1)
        return -1;
    pid = fork();
    if (pid == -1)
        return -1;
    if (pid == 0)
        child_process_exec(pipefd, binary, args, input_file);
    *output = read_from_pipe(pipefd);
    if (*output == NULL)
        return -1;
    exit_status = get_exit_status(pid);
    return exit_status;
}
