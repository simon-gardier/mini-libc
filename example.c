#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //ft_printf usage example
    char name[] = "Simon";
    ft_printf("What a nice name have %s!\n", name);

    //ft_get_next_line usage example
    char file_name[] = "foo.txt";
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        int error = errno;
        ft_printf("Error opening [%s]: %s\n", file_name, strerror(error));
    }
    char* first_line = ft_get_next_line(fd);
    ft_printf("First line of %s : %s\n", file_name, first_line);
    free(first_line);
    close(fd);

    return 0;
}
