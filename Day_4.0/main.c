#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

void parse_line(char *line);

int main(void)
{
	int		fd;
	char	*line;

	fd = open("files/test.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	while ((line = get_next_line(fd)) != NULL)
	{
		/* Parse line */
		parse_line(line);


		free(line);
	}	
	close(fd);

	return 0;
}

void parse_line(char *line)
{
	int		i;
	
	i = 0;
	while (line[i])
	{
		printf("%c", line[i]);
		i++;
	}

	return ;
}
