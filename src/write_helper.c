/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** write_helper.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../include/my.h"

static void write_in_file(char *filename, const char *format, va_list args)
{
    FILE *fp = fopen(filename, "a");

    if (fp == NULL)
        return;
    if (vfprintf(fp, format, args) < 0)
        return;
    fclose(fp);
}

static void write_in_standard_output(const char *format, va_list args)
{
    if (vprintf(format, args) < 0)
        return;
}

void write_output(char *filename, const char *format, ...)
{
    va_list args1;
    va_list args2;

    if (format == NULL)
        return;
    va_start(args1, format);
    va_copy(args2, args1);
    if (filename != NULL) {
        write_in_file(filename, format, args1);
    } else {
        write_in_standard_output(format, args2);
    }
    va_end(args1);
    va_end(args2);
}
