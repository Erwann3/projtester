/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <dirent.h>
    #include <stdbool.h>
    #include "options.h"
    #include "parse_file.h"

void parse_options(options_t *options, int argc, char **argv);
void tree_directory_display(char *str_dir, int indent);
void handle_options(options_t options);
const char *get_name(const char *path);
void recursive_call(char *str_dir, const char *name, int indent);
void recursive_call2(options_t *options, const char *name);
char **read_args_from_file(char *filename, int *arg_count);
void print_args(char **args, int arg_count);
void free_args(char **args, int arg_count);
char *find_binary_in_path(char *name);
char *find_binary_in_folder(char *name);
int execute_bft(char *binary, char **args,
    char **output, char *input_file);
int dir_sort(const struct dirent **a, const struct dirent **b);
void execute_test(options_t *options);
char *trim(char *filename);
char **split_string(char *str, const char *delimiter, int *num_tokens);
void free_tokens(char **tokens, int num_tokens);
void display_token(char *path, char **tokens,
    options_t *options, int num_tokens);
char *find_binary_name(char *name);
char *get_input_value(char *input);
void write_output(char *filename, const char *format, ...);
char *get_input(options_t *options, char *path);
void display_error(void);
char *rm_line(char *str);
void parse_result(options_t *options, char *path);
void remove_newline(char *token);
void handle_output(options_t *options, char *output);

#endif
