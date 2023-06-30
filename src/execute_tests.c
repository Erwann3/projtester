/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** execute_tests.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "../include/my.h"

static void handle_directory(options_t *options, struct stat s,
    char *original_path, char *path)
{
    if (S_ISDIR(s.st_mode)) {
        options->path = path;
        execute_test(options);
        options->path = original_path;
    }
}

void recursive_call2(options_t *options, const char *name)
{
    struct stat s;
    int required_size = strlen(options->path) + strlen(name) + 2;
    char *path = malloc(required_size + 1);
    char *temp_path = malloc(required_size + 1);
    int num_tokens = 0;
    char **args = NULL;
    char *original_path = options->path;

    strcpy(path, options->path);
    strcat(path, "/");
    strcat(path, name);
    strcpy(temp_path, path);
    args = split_string(temp_path, "/", &num_tokens);
    parse_result(options, path);
    display_token(path, args, options, num_tokens);
    if (stat(path, &s) == 0)
        handle_directory(options, s, original_path, path);
    free(temp_path);
    free(path);
}

void execute_test(options_t *options)
{
    struct dirent **namelist;
    int n = scandir(options->path, &namelist, NULL, dir_sort);

    if (n < 0)
        return;
    while (n--) {
        if (strcmp(namelist[n]->d_name, ".") != 0
            && strcmp(namelist[n]->d_name, "..") != 0) {
            recursive_call2(options, namelist[n]->d_name);
        }
        free(namelist[n]);
    }
    free(namelist);
}
