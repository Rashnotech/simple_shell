#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;


char *getpath(char *cmd);
void get_environ_var(void);
char **command_tokenizer(char *command, char ***argv, ssize_t num_char);
int _setenv(char *var_name, char *value);
int execute(char **argv, char *name);

/***WRITERS AND STRING***/

int _putchar(char c);
void _puts(const char *str);
int _strlen(const char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
char *_memcpy(char *dest, char *src, unsigned int i);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);

/***HANDLE ERROR***/
void _puterror(char *name, char *cmd);


ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

void freearray(char ***av);

int check(char **argv);
int _unsetenv(char *var_name);
#endif
