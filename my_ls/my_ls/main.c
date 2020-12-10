#include "my_ls.h"

int main(int ac, char** av)
{
    int fileCount = count_files(".");
    file* files = init_files(fileCount);
    save_file_info(files, ".");

    t_opt* opt = get_opt(ac, av, files, fileCount);
    print_opt(opt, files, fileCount);

    free_opt(opt);
    free_file(files, fileCount);
    return 0;
}