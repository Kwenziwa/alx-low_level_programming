#include "main.h"
#include <stdio.h>

int close_on_error(int file_descriptor);
void read_on_error(char *file_name);
void write_on_error(char *file_name);

/**
 *main - copies the content of a file to another file.
 *@argument_counter: argument counter.
 *@argument_vector: argument vector.
 *Return: always return 0, or exit.
 */
int main(int argument_counter, char *argument_vector[])
{
	ssize_t counted_bytes = 1;
	char buffer[1024];
	int file_from, file_to;

	/*check number of argument */
	if (argument_counter != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/*open and check file_from */
	file_from = open(argument_vector[1], O_RDONLY);
	if (file_from < 0)
	{
		read_on_error(argument_vector[1]);
		exit(98);
	}

	/*open and check  file_to */
	file_to = open(argument_vector[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to < 0)
	{
		write_on_error(argument_vector[2]);
		close_on_error(file_from);
		exit(99);
	}

	/*copy content - loop checks end of file (file_from) */
	while (counted_bytes)
	{
		/*read the next 1020 bytes in file_from and check read error */
		counted_bytes = read(file_from, buffer, 1024);
		if (counted_bytes < 0)
		{
			read_on_error(argument_vector[1]);
			close_on_error(file_from);
			close_on_error(file_to);
			exit(98);
		}

		/*check buffer end of file */
		if (counted_bytes == 0)
			break;
		/*write the output in file_to and check write error */
		counted_bytes = write(file_to, buffer, counted_bytes);
		if (counted_bytes < 0)
		{
			write_on_error(argument_vector[2]);
			close_on_error(file_from);
			close_on_error(file_to);
			exit(99);
		}
	}

	/*close and check  file_from and file_to */
	if (close_on_error(file_from) < 0)
	{
		close_on_error(file_to);
		exit(100);
	}

	if (close_on_error(file_to) < 0)
		exit(100);
	return (0);
}

/**
 *close_on_error - close a file descriptor and check for a possible error.
 *@file_descriptor: file descriptor for file to be closed.
 *Return: 1 if file_descriptor colud be closeed, -1 if file_descriptor could not be closed.
 */
int close_on_error(int file_descriptor)
{
	int close_output;

	close_output = close(file_descriptor);
	if (close_output < 0)
		dprintf(STDERR_FILENO, "Error: Can't close file_descriptor %d\n", file_descriptor);
	return (close_output);
}

/**
 *read_on_error - print the read error.
 *@file_name: file_name.
 */
void read_on_error(char *file_name)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
}

/**
 *write_on_error - print the write error.
 *@file_name: file_name.
 */
void write_on_error(char *file_name)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name);
}

