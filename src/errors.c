/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** errors.c
*/

#include <stdio.h>
#include <stdlib.h>

void display_error(void)
{
    fprintf(stdout, "%s\n", "Error: binary not found.");
    exit(84);
}
