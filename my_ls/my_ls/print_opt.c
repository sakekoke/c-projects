#include "my_ls.h"

void sort(file* files, t_opt* opt, int len, int operand);
void flip(char* first, char* second);
int* has_file_operand(int* files, int len);
void output(t_opt* opt, file* files, int* operands, int len);
void printDir(file* files, t_opt* opt, int len);

void print_opt(t_opt* opt, file* files, int len)
{
    if (opt->wrongOpt == 0)
    {
        sort(files, opt, len, 0);
        int* operands = has_file_operand(opt->files, len);
        output(opt, files, operands, len);
        free(operands);
    }
    else
    {
        printf("my_ls: invalid option -- '%c'\n", opt->wrongOpt);
    }
}

void sort(file* files, t_opt* opt, int len, int operand)
{
    int index, next;
    long int temp;

    for (index = 0; index < len; index += 1)
    {
        for (next = index + 1; next < len; next += 1)
        {
            if (opt->t != 0)
            {
                if (files[index].time < files[next].time)
                {
                    temp = files[index].time;
                    files[index].time = files[next].time;
                    files[next].time = temp;

                    flip(files[index].name, files[next].name);
                    if (operand == 0)
                    {
                        temp = opt->files[index];
                        opt->files[index] = opt->files[next];
                        opt->files[next] = temp;
                    }
                }
            }
            else
            {
                if (my_strcmp(files[index].name, files[next].name) > 0)
                {
                    flip(files[index].name, files[next].name);

                    if (operand == 0)
                    {
                        temp = opt->files[index];
                        opt->files[index] = opt->files[next];
                        opt->files[next] = temp;
                    }
                }
            }
        }
    }
}

void flip(char* first, char* second)
{
    char temp[256];

    my_strcpy(temp, first);
    my_strcpy(first, second);
    my_strcpy(second, temp);
}

int* has_file_operand(int* files, int len)
{
    int index = 0;
    int* operands = init_int_array(2);

    while (index < len)
    {
        if (files[index] == 1)
        {
            operands[0] += 1;
        }
        else if (files[index] == 2)
        {
            operands[1] += 1;
        }
        index += 1;
    }

    return operands;
}

void output(t_opt* opt, file* files, int* operands, int len)
{
    int index = 0, dirCount = 1;

    if (operands[0] != 0)
    {
        while (index < len)
        {
            if (opt->files[index] == 1)
            {
                printf("%s  ", files[index].name);
            }
            index += 1;
        }
        printf("\n");
    }
    if (operands[1] != 0)
    {
        index = 0;
        if (operands[0] != 0)
        {
            printf("\n");
        }
        while (index < len)
        {
            int count;
            if (opt->files[index] == 2)
            {
                if (operands[0] != 0 || operands[1] > 1)
                {
                    printf("%s:\n", files[index].name);
                }

                count = count_files(files[index].name);
                file* thisDir = init_files(count);
                save_file_info(thisDir, files[index].name);
                sort(thisDir, opt, count, 2);
                printDir(thisDir, opt, count);
                free_file(thisDir, count);

                if (dirCount < operands[1])
                {
                    printf("\n");
                    dirCount += 1;
                }
            }
            index += 1;
        }
    }
    else if (opt->wrongFiles == 0)
    {
        printDir(files, opt, len);
    }
}

void printDir(file* files, t_opt* opt, int len)
{
    int index = 0;
    while (index < len)
    {
        if (opt->a == 0)
        {
            if (files[index].name[0] == '.')
            {
                index += 1;
                continue;
            }
        }
        printf("%s  ", files[index].name);
        index += 1;
    }
    printf("\n");
}