#include "get_next_line.h"
#include <stdio.h>
int main()
{
    int fd1 = open("testing", O_RDONLY);
    //int	fd2 = open("text.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    close(fd1);
    /*printf("%d\n", fd1);
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    printf ("\n");
    close(fd1);

    printf("%d\n", fd2);
    while ((line = get_next_line(fd2)) != NULL)
    {	
        printf("%s", line);
        free(line);
    }
    close(fd2);
    return (0);*/

}
