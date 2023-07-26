#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

extern char **environ;

/* String management */
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t len);
char *_strdbl(char *str);
char *_strchr(char *s, char c);
int _isalpha(int c);
int _atoi(char *s);
int _putchar(char c);
void _puts(char *str);
void manage_sig(__attribute__((unused))int signal_n);
int _strconslen(const char *str);
char *_itoa(int num);

/* Memory management */
void set_to0(unsigned int *arr, size_t size);
void set_null(char *arr, size_t size);
char *_memset(char *s, char b, unsigned int n);
void free_mem(char **mem);
void *_realloc(void *ptr, unsigned int prv_size, unsigned int new_size);

/* Separation */
int count_word(char *str);
int delimiter(char *str, char *deli);

/* Environment */
void manage_help(void);
void print_env(void);
char *get_envi(const char *name);
char *rm_new_line(char *str);

void manage_exit(char **usertok, char *l);
void manage_help(void);
char **tok_str(char *buf);

/* Freeing */
void frees_get_env(char *var);
void free_token(char **tok);
int free_p(void **ptr);

/* Change directory */
void cd_pwd(char **args);
void ch_directory(char **directories, char *cmd);


int _execute(char *cmd, char **ops);
int execute_builtin(char **usertok, char *line);

char **str_tok(char *str, char *deli, int n);
char *con_path(char *pathname, char *progname);
char *check_cmd(char *cn);

void print_error(char *argv, int count, char *cmd, char *msg);
char *handle_comment(char *s);

#endif
