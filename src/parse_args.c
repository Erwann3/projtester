/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** parse_args.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void parse_options(options_t *options, int argc, char **argv)
{
    options->path = argv[1];
    if (argc >= 3)
        options->command = argv[2];
    if (argc == 4)
        options->output_file = argv[3];
}

void handle_options(options_t options)
{
    DIR *dir = opendir(options.path);

    if (dir == NULL)
        exit(84);
    if (options.command == NULL && options.path != NULL
        && options.output_file == NULL) {
        printf("%s\n", get_name(options.path));
        tree_directory_display(options.path, 5);
    }
    if (options.path != NULL && options.command != NULL)
        execute_test(&options);
}
