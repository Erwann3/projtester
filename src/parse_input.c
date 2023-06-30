/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** parse_input.c
*/

#include <string.h>

char *get_input_value(char *input)
{
    char *delimiter = ":";
    char *token = NULL;
    char *result = NULL;

    token = strstr(input, delimiter);
    if (token != NULL)
        result = strtok(token + 1, delimiter);
    return result;
}
