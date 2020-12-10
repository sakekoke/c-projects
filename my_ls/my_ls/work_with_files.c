#include "my_ls.h"

int count_files(char* directory)
{
    DIR* folder;
    struct dirent* entry;
    int count = 0;

    folder = opendir(directory);

    while ((entry = readdir(folder)))
    {
        count += 1;
    }

    closedir(folder);
    return count;
}

void save_file_info(file* files, char* directory)
{
    DIR* folder;
    struct dirent* entry;
    struct stat filestat;
    int index = 0;

    folder = opendir(directory);

    while ((entry = readdir(folder)))
    {
        stat(entry->d_name, &filestat);
        files[index].type = S_ISDIR(filestat.st_mode) ? 1 : 0;
        files[index].time = filestat.st_mtim.tv_sec;
        my_strcpy(files[index].name, entry->d_name);
        index += 1;
    }
    closedir(folder);
}