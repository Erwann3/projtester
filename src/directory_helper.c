/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** directory_helper.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../include/my.h"

static void print_indent(int indent)
{
    char *dashes = malloc(indent + 1);

    memset(dashes, '-', indent);
    dashes[indent] = 0;
    printf("%s", dashes);
    free(dashes);
}

int dir_sort(const struct dirent **a, const struct dirent **b)
{
    return strcasecmp((*b)->d_name, (*a)->d_name);
}

const char *get_name(const char *path)
{
    char separator = '/';
    int sepIndex = -1;
    int pathSize = 0;
    int pathEntireLength = strlen(path);
    char *name = NULL;

    for (; pathEntireLength > 1
        && path[pathEntireLength - 1] == separator; pathEntireLength--);
    for (int i = 0; path[i] != 0 && i < pathEntireLength; i++) {
        if (path[i] == separator)
            sepIndex = i;
        pathSize++;
    }
    if (sepIndex == -1)
        return path;
    name = (char *) malloc(pathSize - sepIndex + 1);
    name[pathSize - sepIndex] = 0;
    for (int i = 0; i < pathSize - sepIndex - 1; i++)
        name[i] = path[sepIndex + i + 1];
    return name;
}

void recursive_call(char *str_dir, const char *name, int indent)
{
    struct stat s;
    int required_size = strlen(str_dir) + strlen(name) + 2;
    char *path = malloc(required_size + 1);

    strcpy(path, str_dir);
    strcat(path, "/");
    strcat(path, name);
    print_indent(indent);
    printf("%s\n", name);
    if (stat(path, &s) == 0) {
        if (S_ISDIR(s.st_mode))
            tree_directory_display(path, indent + 5);
    }
    free(path);
}

void tree_directory_display(char *str_dir, int indent)
{
    struct dirent **namelist;
    int n = scandir(str_dir, &namelist, NULL, dir_sort);

    if (n < 0)
        return;
    while (n--) {
        if (strcmp(namelist[n]->d_name, ".") != 0
            && strcmp(namelist[n]->d_name, "..") != 0) {
            recursive_call(str_dir, namelist[n]->d_name, indent);
        }
        free(namelist[n]);
    }
    free(namelist);
}
