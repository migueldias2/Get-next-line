/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:02:59 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/23 13:23:14 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_until_nl(int fd, char *str)
{
	char	temp[BUFFER_SIZE + 1];
	int		chars_read;
	int		i;

	i = 0;
	while (i < BUFFER_SIZE)
		temp[i++] = '\0';
	chars_read = 1;
	while (!ft_strchr(temp, '\n') && chars_read)
	{
		chars_read = read(fd, temp, BUFFER_SIZE);
		if (chars_read < 0 || (!chars_read && !str))
			return (NULL);
		temp[chars_read] = '\0';
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
	static char	*string[MAX_FD];
	char		*final_string;
	char		*remaining_chars;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	string[fd] = get_until_nl(fd, string[fd]);
	if (!string[fd])
		return (NULL);
	while (string[fd][i] != '\n' && string[fd][i])
		i++;
	if (string[fd][i] == '\n')
		i++;
	final_string = ft_substr(string[fd], 0, i);
	remaining_chars = ft_substr(string[fd], i, ft_strlen(string[fd]) - i);
	free(string[fd]);
	string[fd] = remaining_chars;
	return (final_string);
}
/*int	main(void)
{
	int		fd1, fd2;
	char	*line;

	fd1 = open("file1.txt", O_RDONLY);
	if (fd1 < 0)
		return (1);
	fd2 = open("file2.txt", O_RDONLY);
	if (fd2 < 0)
	{
		close(fd1);
		return (1);
	}
	printf("Contents of file1.txt:\n");
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd1);
	printf("\nContents of file2.txt:\n");
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd2);
	return (0);
}*/
