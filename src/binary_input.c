/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** binary_input.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include "../include/my.h"

char *get_input(options_t *options, char *path)
{
    char *new_string = NULL;
    char *directory_name = NULL;
    if (options->file == NULL)
        return path;
    directory_name = strdup(path);
    if (directory_name == NULL)
        return NULL;
    directory_name = dirname(directory_name);
    new_string = calloc(strlen(directory_name)
        + strlen(options->file) + 2, sizeof(char));
    if (new_string == NULL) {
        free(directory_name);
        return NULL;
    }
    strcat(new_string, directory_name);
    strcat(new_string, "/");
    strcat(new_string, options->file);
    free(directory_name);
    return new_string;
}

char *rm_line(char *str)
{
    int last_character = strlen(str) - 1;

    if (str == NULL)
        return NULL;
    if (str[last_character] == '\n')
        str[last_character] = 0;
    return str;
}
