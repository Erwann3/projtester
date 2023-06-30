/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** binary_helper.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

char *find_binary_in_path(char *name)
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *token = strtok(path_copy, ":");
    char *binary = NULL;
    char *slash = "/";

    while (token != NULL) {
        binary = malloc(sizeof(char) * (strlen(token) + strlen(name) + 2));
        binary = strcpy(binary, token);
        binary = strcat(binary, slash);
        binary = strcat(binary, name);
        if (access(binary, F_OK) == 0 && access(binary, X_OK) == 0) {
            free(path_copy);
            return binary;
        }
        free(binary);
        token = strtok(NULL, ":");
    }
    free(path_copy);
    return NULL;
}

char *find_binary_in_folder(char *name)
{
    if (access(name, F_OK) == 0 && access(name, X_OK) == 0)
        return name;
    return NULL;
}
