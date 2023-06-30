/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** awaited_results.c
*/

#include <string.h>
#include "../include/my.h"

void handle_output(options_t *options, char *output)
{
    if (options->result != NULL) {
        remove_newline(output);
        if (strcmp(options->result, output) == 0)
            write_output(options->output_file, " OK\n");
        else
            write_output(options->output_file, " KO\n");
        return;
    }
    if (output != NULL && strlen(output) > 1)
        write_output(options->output_file, " %s\n", rm_line(output));
    else
        write_output(options->output_file, "\n");
}
