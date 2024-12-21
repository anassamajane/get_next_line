#include "get_next_line.h"
#include <stdio.h>
int main()
{
    int fd1 = open("testing", O_RDONLY);
    int	fd2 = open("text.txt", O_RDONLY);
    int	fd3 = open("test", O_RDONLY);

    char	*line;
    line = get_next_line(fd1);
    printf ("%s", line);
    line = get_next_line(fd2);
    printf ("%s", line);
    line = get_next_line(fd3);
    printf ("%s", line);

    /*if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
    */
}
