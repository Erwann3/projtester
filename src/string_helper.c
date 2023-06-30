/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** string_helper.c
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

char *trim(char *filename)
{
    char *dot = strrchr(filename, '.');

    if (dot && !strcmp(dot, ".tdf"))
        *dot = 0;
    return filename;
}

char **split_string(char *str, const char *delimiter, int *num_tokens)
{
    char **tokens = NULL;
    char *token = strtok(str, delimiter);
    int count = 0;

    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char*) * (count + 1));
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, delimiter);
    }
    *num_tokens = count;
    return tokens;
}

static void display_args(options_t *options, char **tokens, int i)
{
    if (strstr(tokens[i], ".tdf") != NULL) {
        write_output(options->output_file, "%s:", trim(tokens[i]));
    } else {
        write_output(options->output_file, "[%s] ", tokens[i]);
    }
}

void display_token(char *path, char **tokens,
    options_t *options, int num_tokens)
{
    int args_count = 0;
    char **args = read_args_from_file(path, &args_count);
    char *output = NULL;
    char *binary_name = find_binary_name(options->command);

    if (binary_name == NULL)
        display_error();
    if (strstr(tokens[num_tokens - 1], ".tdf") == NULL) {
        free(output);
        return;
    }
    for (int i = 2; i < num_tokens; i++)
        display_args(options, tokens, i);
    execute_bft(binary_name, args, &output, get_input(options, path));
    handle_output(options, output);
    free(output);
    free_tokens(args, args_count);
}

void free_tokens(char **tokens, int num_tokens)
{
    for (int i = 0; i < num_tokens; i++)
        free(tokens[i]);
    free(tokens);
}
