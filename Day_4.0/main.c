#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

int main(void)
{
	int		fd;
	int		atoied;
	char	*line;
	char	*str = "42zed";

	atoied = ft_atoi(str);
	ft_printf("Atoied : %i\n", atoied);

	fd = open("files/test.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s\n", line);
		free(line);
	}	
	close(fd);

	return 0;
}
