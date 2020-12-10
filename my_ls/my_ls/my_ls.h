#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct t_opt
{
    int a;
    int t;
    int wrongOpt;
    int* files;
    _Bool wrongFiles;
} t_opt;

typedef struct file
{
    char* name;
    long int time;
    _Bool type;
} file;

// work_with_files.c
int count_files(char* directory);
void save_file_info(file* files, char* directory);

t_opt* get_opt(int ac, char** av, file* files, int len);
void print_opt(t_opt* opt, file* files, int len);

// init.c
t_opt* init_opt(int len);
int* init_int_array(int len);
file* init_files(int len);

// free.c
void free_opt(t_opt* opt);
void free_file(file* files, int len);

// my.c
void my_strcpy(char* first, char* second);
int my_strcmp(char* first, char* second);