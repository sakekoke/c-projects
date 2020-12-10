#include "my_ls.h"

int my_strcmp(char* first, char* second)
{
    int index = 0;

	while(first[index] != '\0')
	{
		if (first[index] != second[index])
        {
            break;
        }
        index += 1;
	}

	return first[index] - second[index];
}

void my_strcpy(char* first, char* second)
{
    int index = 0;
    
    while (second[index] != '\0')
    {
        first[index] = second[index];
        index += 1;
    }
    first[index] = '\0';
}