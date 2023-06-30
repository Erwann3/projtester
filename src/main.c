/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** main.c
*/

#include <stdio.h>
#include "../include/my.h"

int main(int argc, char **argv)
{
    options_t options;

    options.path = NULL;
    options.command = NULL;
    options.file = NULL;
    options.output_file = NULL;
    options.result = NULL;
    if (argc <= 1 || argc > 4)
        return 84;
    parse_options(&options, argc, argv);
    handle_options(options);
}
