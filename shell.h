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

extern char **environ;
char *my_getpath(char *cmd);
int tokenizer(char *command, char ***argv, ssize_t num_char);
int command_execute(char **argv, char *name);
int continue_main(char *input, char **argv, char *name,
		size_t no_char, int argc);

/***************EMVIRONMENT FUNCTIONS***************/
int my_unsetenv(char *var_name);
char *my_getenv(char *var_name);
void my_environ(void);
int my_setenv(char *var_name, char *value);
int _setenv(char *name, char *value, int overwrite);
int print_prompt(int argc);
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

/********************HANDLE ERROR********************/
int error_putchar(char c);
void error_puts(const char *str);
int errorput_number(int i);
void handle_error(char *name, char *cmd);

/*****************ADVANCED FUNCTIONS****************/
ssize_t _getline(char **lineptr, size_t *n, int fd);
size_t _readline(char **lineptr, size_t *n, char buffer[], int fd, int size);
char *_strtok(char *str, const char *delim);
int handle_operators(char *input, char *name, ssize_t no_char,
		int argc, char *delim);
char *my_strtok(char *str, const char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t my_strspn(char *str, const char *delim);
size_t my_strcspn(char *str, const char *delim);
void free_arrays(char ***av);
int clean_up(char **argv, char *lineptr, int argc);
int exit_cmd(char *name, char **argv, char *lineptr);
/***************IN_BUILT FUNCTIONS***************/
int in_built(char *name, char **argv, char *lineptr, int argc);
void change_dir(char *dir);
void signalHandle(int signum);
void file_handler(char *file, char *programe_name, int argc);

/********************EXIT FUNCTIONS*****************/
void normal_exit(int errorcode);
void handle_exit(char *name, char *cmd, int code);
#endif
