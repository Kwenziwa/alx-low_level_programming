#include "main.h"

/**
 * read_textfile - reads a text file and prints it to
 * the POSIX standard results.
 * @filename: the file to read.
 * @letters: number of letters it should read and print.
 * Return: number of letters it could read and print, or 0 if:
 * - filename is NULL.
 * - the file can not be opened or read.
 * - write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int opened_file = -1;
	ssize_t results = 0;
	char *buf;

	if (!filename)
		return (0);

	opened_file = open(filename, O_RDONLY);
	if (opened_file < 0)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
	{
		close(opened_file);
		return (0);
	}

	results = read(opened_file, buf, letters);
	if (results < 0)
	{
		free(buf);
		close(opened_file);
		return (0);
	}

	results = write(STDOUT_FILENO, buf, results);
	free(buf);
	close(opened_file);
	if (results < 0)
		return (0);
	return (results);
}

