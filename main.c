/*
** EPITECH PROJECT, 2018
** HexDump
** File description:
** Example main function
*/

#include "hexdump.h"

int main(int ac, char *av[])
{
	if (ac != 2)
		return EXIT_FAILURE;

	FILE *fp = fopen(av[1], "r");
	if (!fp)
		return EXIT_FAILURE;

	fseek(fp, 0, SEEK_END);
	size_t length = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	uint8_t data[length];
	memset(data, 0, length);

	if (fread(data, sizeof(uint8_t), length, fp) != length) {
		fclose(fp);
		return EXIT_FAILURE;
	}

	hexdump_to(stdout, data, length);

	fclose(fp);
	return EXIT_SUCCESS;
}