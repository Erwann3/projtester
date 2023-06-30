/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** result_helper.c
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/my.h"
#include "../include/parse_file.h"

static void parse_args(options_t *options, char *line)
{
    if (strncmp(line, "INPUT:", 6) == 0) {
        remove_newline(line + 6);
        options->file = strdup(line + 6);
    }
    if (strncmp(line, "RESULT:", 7) == 0) {
        remove_newline(line + 7);
        options->result = strdup(line + 7);
    }
}

static void display_result(FILE *fp, options_t *options)
{
    char *line = NULL;
    size_t len = 0;
    int read = 0;

    read = getline(&line, &len, fp);
    while (read != -1) {
        parse_args(options, line);
        read = getline(&line, &len, fp);
    }
    free(line);
}

void parse_result(options_t *options, char *path)
{
    FILE *fp = fopen(path, "r");
    display_result(fp, options);
    fclose(fp);
}
