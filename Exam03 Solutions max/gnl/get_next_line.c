#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return(i);
}

char	*ft_strjoin(char *remains, char *buffer)
{
	char *array;
	unsigned int size;
	int i = 0;
	int j = 0;

	if (!remains && !buffer)
		return (NULL); // return NULL if !remains and !buffer
	size = ft_strlen(remains) + ft_strlen(buffer);
	if (!(array = (char *)malloc(sizeof(char) * (size + 1)))) // allocate memory for array remains + buffer
		return(NULL);
	if (remains)
	{
		while (remains[i])
			array[j++] = remains[i++]; // copy string in remains into array
		i = 0;
	}
	while (buffer[i]) // copy whats in buffer into array, hence allocation remains + buffer
		array[j++] = buffer[i++];
	array[size] = '\0'; // NULL terminate
	free(remains);
	return (array);
}

int ft_strchr (char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i = i + 1;
	}
	return (0);
}

char	*push_line (char *remains)
{
	int		i = 0;
	char	*array;

	while (remains[i] && remains[i] != '\n') // figure out lenght of line
		i++;
	if (remains[i] == '\n') 	// if newline char, account for it as well
		i++;
	if (!(array = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);	// allocate memory for line
	i = 0;
	while (remains[i] && remains[i] != '\n') // while there is a line
	{
		array[i] = remains[i]; // copy line into array
		i++;
	}
	if (remains[i] == '\n') // if there is a newline, copy n	if (buffer)wline char and null terminate array
	{
		array[i] = '\n';
		i++;
	}
	array[i] = '\0';
	return (array);
}

char *cut_next_line(char *remains)
{
	int i = 0;
	int j = 0;
	char *array;

	while (remains[i] && remains[i] != '\n') // figure out lenghts next line
		i++;
	if (!remains[i]) // if remains is empty, free it and return NULL
	{
		free(remains);
		return (NULL);
	}
	if (!(array = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1)))) // allocate memory for the remains after the "next line" has been cut
		return (NULL); // return NULL if malloc fails
	i++; // skip newline char
	while (remains[i])
	{
		array[j] = remains[i]; // copy the remaining string into array;
		i++;
		j++;
	}
	array[j] = '\0'; // NULL Terminate
	free(remains); // free remains, since it's no longer needed, remainder is stored in array
	return (array);
}

char	*get_next_line(int fd)
{
	static char	*remains;
	char *line;
	int count = 1;
	char buffer[BUFFER_SIZE + 1];
	buffer[0] = '\0';

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0) // account for possible errors.
		return (NULL);

	while(!ft_strchr(buffer) && count != 0)
	{
		if ((count = read(fd, buffer, BUFFER_SIZE)) == (-1)) // if read encountered an error, return NULL
			return (NULL);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	line = push_line(remains);
	remains = cut_next_line(remains);
	if (line[0] == '\0') // if EOF has been reached, free line and return NULL
	{
		free(line);
		return (NULL);
	}
	return (line);
}