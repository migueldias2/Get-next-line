#include "get_next_line.h"

char	*get_until_nl(int fd, char *str)
{
	char	temp[BUFFER_SIZE + 1];
	int		chars_read;
	int		i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
		temp[i++] = '\0';
	chars_read = 1;
	while (!ft_strchr(temp, '\n') && chars_read)
	{
        chars_read = read(fd, temp, BUFFER_SIZE);
		if (chars_read < 0)
        {
            free(str);
            return (NULL);
        }
		if (!str)
			str = ft_strdup(temp);
		else
			str = ft_strjoin(str, temp);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*final_string;
	char		*remaining_chars;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	string = get_until_nl(fd, string);
	if (!string)
		return (NULL);
	while (string[i] != '\n' && string[i])
		i++;
	if (string[i] == '\n')
		i++;
	final_string = ft_substr(string, 0, i);
	if (!final_string)
		return (NULL);
	remaining_chars = ft_substr(string, i, ft_strlen(string) - i);
	if (!remaining_chars)
		return (NULL);
	free(string);
	string = remaining_chars;
	return (final_string);
}
int	main()
{
	int	fd;
	char	buf[BUFFER_SIZE + 1];
	int	chars_read;
	int	line = 1;

	fd = open("file.txt", O_RDONLY);
	while (chars_read = read(fd, buf, BUFFER_SIZE))
	{
		line++;
		buf[chars_read] = '\0';
		printf("line %d -> %s", line, buf);
		free(line);
	}
	close (fd)
	return (0);
}