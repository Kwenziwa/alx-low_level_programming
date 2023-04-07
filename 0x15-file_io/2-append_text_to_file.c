#include "main.h"

/**
 *append_text_to_file - function that appends text at the end of a file..
 *@filename: name of the file to append the text.
 *@text_content: the NULL terminated string to add at the end of the file.
 *Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int opened_file, len = 0;

	if (!filename)
		return (-1);
	opened_file = open(filename, O_RDWR | O_APPEND);
	if (!(opened_file >= 0))
		return (-1);
	if (!text_content)
	{
		close(opened_file);
		return (1);
	}

	while (text_content[len])
		len++;
	if (write(opened_file, text_content, len) < 0)
	{
		close(opened_file);
		return (-1);
	}

	close(opened_file);
	return (1);
}

