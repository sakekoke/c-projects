#include "my_ls.h"

int is_option(char* str);
void set_option(t_opt* opt, char* str);
void set_files(t_opt* opt, char* str, file* files, int len);

t_opt* get_opt(int ac, char** av, file* files, int len)
{
    t_opt* opt = init_opt(len);
    int index = 1;

    while (index < ac)
    {
        if (is_option(av[index]))
        {
            set_option(opt, av[index] + 1);
        }
        else
        {
            set_files(opt, av[index], files, len);
        }
        index += 1;
    }
    return opt;
}

int is_option(char* str)
{
    if (str[0] == '-')
    {
        return 1;
    }
    return 0;
}

void set_option(t_opt* opt, char* str)
{
    int index = 0;

    while (str[index] != '\0')
    {
        if (str[index] == 'a')
        {
            opt->a = 1;
        }
        else if (str[index] == 't')
        {
            opt->t = 1;
        }
        else
        {
            opt->wrongOpt = str[index];
        }
        index += 1;
    }
}

void set_files(t_opt* opt, char* str, file* files, int len)
{
    int index = 0;
    _Bool wrong = 1;

    while (index < len)
    {
        if (my_strcmp(files[index].name, str) == 0)
        {
            opt->files[index] = (files[index].type == 1) ? 2 : 1;
            wrong = 0;
        }
        index += 1;
    }
    if (wrong == 1)
    {
        opt->wrongFiles = 1;
        printf("my_ls: cannot access '%s': No such file or directory\n", str);
    }
}