#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/wait.h>
#include <signal.h>

char *_prompt(int isattyStatus);
char *buildPath(char **argum, char *fileName, char **env);
char **_sortArguments(char *prompt, char *fileName);
char *env_split(char *path_value, char *command, char *fileName);
int _print_numbers_recursion(int number);
int countArguments(char **arg);
int lengthArray(char *array);
void _error(int status, char **arguments, char *fileName);
char *get_env_value(char *nameVar, char **env);
char **copyEnv(char **env);
int countSpace(char *prompt);
void freeDoublePointer(char **pointer);
void freePointer(char *pointer);

int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif /* SIMPLE_SHELL_H */
