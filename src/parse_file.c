/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** parse_file.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/parse_file.h"

static void parse_args(parse_file_t *ps, char *line)
{
    char *token = NULL;

    if (strncmp(line, "ARGS:", 5) == 0) {
        token = strtok(line + 5, " ");
        while (token != NULL) {
            remove_newline(token);
            (*ps->args)[*ps->arg_count] = strdup(token);
            (*ps->arg_count)++;
            token = strtok(NULL, " ");
        }
    }
}

static void display_file(parse_file_t *ps)
{
    char *line = NULL;
    size_t len = 0;
    int read = 0;

    read = getline(&line, &len, ps->fp);
    while (read != -1) {
        parse_args(ps, line);
        read = getline(&line, &len, ps->fp);
    }
    free(line);
}

char **read_args_from_file(char *filename, int *arg_count)
{
    FILE *fp = fopen(filename, "r");
    int arg_size = 100;
    char **args = calloc(arg_size, sizeof(char *));
    parse_file_t parse_file = {fp, arg_count, &arg_size, &args};

    if (fp == NULL) {
        free_args(args, arg_size);
        exit(84);
    }
    display_file(&parse_file);
    fclose(fp);
    return args;
}

void remove_newline(char *token)
{
    char *newline = strchr(token, '\n');

    if (newline)
        *newline = 0;
}

void free_args(char **args, int arg_count)
{
    for (int i = 0; i < arg_count; i++)
        free(args[i]);
    free(args);
}
