#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>


extern char **environ;

/**
 * struct Shell - information about current shell
 * @argc: int - number of command line arguments
 * @fd: int - File discriptor
 * @num_commands: int - number of command
 * @error_code: int - error code
 * @argv: char ** - command line arguments
 * @is_interactive: int - interactive
 * @file: char * - file name
 */

typedef struct Shell
{
	int argc;
	int fd;
	int num_commands;
	int error_code;
	char **argv;
	int is_interactive;
	char *file;
} shell_t;

void *my_malloc(unsigned int size);

char *my_getpath(char *cmd);
char ***tokenizer(shell_t *shell, char *command, ssize_t num_char);
int command_execute(char **argv, char *name);
int continue_main(shell_t *shell, char *input, size_t no_char);

/***************EMVIRONMENT FUNCTIONS***************/
int my_unsetenv(char *var_name);
char *my_getenv(char *var_name);
void my_environ(void);
int my_setenv(char *var_name, char *value);
int _setenv(char *name, char *value, int overwrite);
void print_prompt(void);
char *get_input(int fd, ssize_t *no_char);
char *_getenv(const char *name);
int _atoi(const char *s);

/**********************WRITERS**********************/
int put_number(int i);
int my_putchar(char c);
void my_puts(const char *str);

/*******************STRINGS_HANDLER******************/
int my_strlen(const char *str);
char *my_strcpy(char *dest, char *src);
char *my_strdup(const char *str);
char *my_memcpy(char *dest, const char *src, unsigned int n);
int my_strcmp(const char *str1, const char *str2);
char *my_strcat(char *dest, char *src);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(char *str, char c);
char *_strstr(char *haystack, char *needle);
char *_strncpy(char *dest, char *src, int n);
int _strspn(char *s, char *accept);
int _strcspn(char *s, char *reject);
/********************HANDLE ERROR********************/
int error_putchar(char c);
void error_puts(const char *str);
int errorput_number(int i);
int handle_error(char *name, char *cmd);

/*****************ADVANCED FUNCTIONS****************/
ssize_t _getline(char **lineptr, size_t *n, int fd);
size_t _readline(char **lineptr, size_t *n, char buffer[], int fd, int size);
char *_strtok(char *str, const char *delim);

char *my_strtok(char *str, const char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t my_strspn(char *str, const char *delim);
size_t my_strcspn(char *str, const char *delim);
void free_arrays(char ***av);
void free_command(shell_t *shell, char ***command);
int clean_up(char **argv, char *lineptr, int argc);
int exit_cmd(char *name, char **argv, char *lineptr, int status);

/***************IN_BUILT FUNCTIONS***************/
int in_built(shell_t *shell, char **argv, char *lineptr);
void change_dir(char *dir);
void signalHandle(int signum);

/********************EXIT FUNCTIONS*****************/
void normal_exit(int errorcode);
int handle_exit(char *name, char *cmd, char *code);



void initialize(shell_t *shell, int argc, char **av);
int check_input(shell_t *shell, size_t no_char, char *input);

#endif
