/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-projtester-erwann.tanguy [WSL: Ubuntu-22.04]
** File description:
** tests.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <criterion/redirect.h>
#include <criterion/criterion.h>

Test(my_ps_synthesis, basic_test) {
    FILE *pipe = popen("cat", "w");
    char buffer[1024];
    FILE *output;

    cr_redirect_stdout_to_pipe(pipe);
    my_ps_synthesis();
    pclose(pipe);
    output = cr_get_redirected_stdout();
    fseek(output, 0, SEEK_SET);
    fread(buffer, sizeof(char), sizeof(buffer), output);
    cr_assert(strstr(buffer, "PID") != NULL, "Output does not contain PID");
}
