#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("testing", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char	*line = get_next_line(fd);
    free(line);

    close(fd);
    return (0);
}
