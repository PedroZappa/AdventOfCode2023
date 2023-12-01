#define BUFFER_SIZE 1024

int main(void)
{
	char	*vault;
	char	*read_buffer;
	int		bytes_read;
	int		fd;

	fd = open("calibration-doc.txt", O_RDONLY);
	if (fd == -1)
		return 1;
	read_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_buffer == NULL)
		return 1;	
}
