#include "get_next_line.h"
#include <stdio.h>
/*
int main()
{
    int fd = open("testing", O_RDONLY);
    if (fd < 0)
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
}
*/

int	main()
{
	char	*line;

	line = get_next_line(42);
	printf("%s", line);
}
