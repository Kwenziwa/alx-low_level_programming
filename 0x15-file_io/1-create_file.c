#include "main.h"

/**
 *create_file - creates a file
 *@filename: path of file
 *@text_content: content to be write on new file or truncated on existing
 *Return: 1 on Success, num on failure
 */
int create_file(const char *filename, char *text_content)
{
	int len = 0, opened_file, num = -1, cast_up;

	if (!filename)
		return (num);

	/*Open file */
	opened_file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (num == opened_file)
		return (num);
	if (text_content)
	{
		while (text_content[len])
			len++;
	}

	/*write into a opened file */
	cast_up = write(opened_file, text_content, len);
	if (num == cast_up)
	{
		close(opened_file);
		return (num);
	}

	close(opened_file);
	return (1);
}

