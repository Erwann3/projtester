/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** parse_file.h
*/

#ifndef PARSE_FILE_H
    #define PARSE_FILE_H

    #include <stdio.h>

typedef struct parse_file_s {
    FILE *fp;
    int *arg_count;
    int *arg_size;
    char ***args;
} parse_file_t;

#endif
