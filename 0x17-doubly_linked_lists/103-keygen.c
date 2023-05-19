#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char psword[7], *x_code;
	int len = strlen(argv[1]), i, tempo;

	x_code = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	tempo = (len ^ 59) & 63;
	psword[0] = x_code[tempo];

	tempo = 0;
	for (i = 0; i < len; i++)
		tempo += argv[1][i];
	psword[1] = x_code[(tempo ^ 79) & 63];

	tempo = 1;
	for (i = 0; i < len; i++)
		tempo *= argv[1][i];
	psword[2] = x_code[(tempo ^ 85) & 63];

	tempo = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > tempo)
			tempo = argv[1][i];
	}
	srand(tempo ^ 14);
	psword[3] = x_code[rand() & 63];

	tempo = 0;
	for (i = 0; i < len; i++)
		tempo += (argv[1][i] * argv[1][i]);
	psword[4] = x_code[(tempo ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		tempo = rand();
	psword[5] = x_code[(tempo ^ 229) & 63];

	psword[6] = '\0';
	printf("%s", psword);
	return (0);
}
