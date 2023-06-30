/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** requirement.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

static void assign_variables(char **path_dup, char **token, char *path)
{
    *path_dup = strdup(path);
    *token = strtok(*path_dup, ":");
}

static char *get_cmd_path(const char *cmd)
{
    char *path = getenv("PATH");
    char *path_dup = NULL;
    char *token = NULL;
    char *full_path = NULL;

    if (!path)
        return NULL;
    assign_variables(&path_dup, &token, path);
    while (token) {
        full_path = malloc(strlen(token) + strlen(cmd) + 2);
        sprintf(full_path, "%s/%s", token, cmd);
        if (access(full_path, F_OK | X_OK) == 0) {
            free(path_dup);
            return full_path;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    free(path_dup);
    return NULL;
}

void my_ps_synthesis(void)
{
    char *path = get_cmd_path("ps");
    pid_t pid = fork();

    if (!path)
        return;
    if (pid < 0) {
        free(path);
        return;
    }
    if (pid == 0) {
        execl(path, "ps", NULL);
        exit(84);
    } else {
        wait(NULL);
    }
    free(path);
}
