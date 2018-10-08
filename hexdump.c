/*
** EPITECH PROJECT, 2018
** HexDump
** File description:
** HexDump implementation
*/

#include "hexdump.h"

////////////////////////////////////////////////////////////////////////////////

#ifdef HEXDUMP_SKIP_DUPLICATES
static bool need_reset = true;
#endif

////////////////////////////////////////////////////////////////////////////////

static void dump_row(FILE *stream, size_t row, uint8_t *data, size_t length)
{
#ifdef HEXDUMP_SKIP_DUPLICATES
	static bool is_first_row = true;
	static bool skipped_last = false;
	static uint8_t previous_row[HEXDUMP_ROW_LENGTH];

	if (need_reset) {
		need_reset = false;
		is_first_row = true;
	}

	if (!is_first_row) {
		if (memcmp(previous_row, data, length) == 0) {
			if (!skipped_last)
				fprintf(stream, "*\n");
			skipped_last = true;
			return;
		}
		else {
			skipped_last = false;
		}
	}
	else {
		is_first_row = false;
		memset(previous_row, 0, length);
	}
	memcpy(previous_row, data, length);
#endif

	fprintf(stream, "%08lx ", row);
	for (size_t i = 0; i < HEXDUMP_ROW_LENGTH; ++i) {
		if (i % HEXDUMP_COL_SIZE == 0)
			fprintf(stream, " ");
		if (i >= length)
			fprintf(stream, "   ");
		else
			fprintf(stream, "%02x ", data[i]);
	}
	fprintf(stream, " ");
	for (size_t i = 0; i < length; ++i) {
		if (i % HEXDUMP_COL_SIZE == 0)
			fprintf(stream, "|");
		fprintf(stream, "%c", isprint(data[i]) ? data[i] : '.');
	}
	fprintf(stream, "|\n");
}

void hexdump_to(FILE *stream, void *mem, size_t length)
{
	uint8_t *data = (uint8_t *)mem;
	size_t safe_length = length;
	size_t row = 0;

#ifdef HEXDUMP_SKIP_DUPLICATES
	need_reset = true;
#endif

	while (safe_length % HEXDUMP_ROW_LENGTH != 0)
		--safe_length;

	while (row < safe_length) {
		dump_row(stream, row, &data[row], HEXDUMP_ROW_LENGTH);
		row += HEXDUMP_ROW_LENGTH;
		length -= HEXDUMP_ROW_LENGTH;
	}

	dump_row(stream, row, &data[row], length);
	fprintf(stream, "%08lx\n", row + length);
}

void hexdump(void *mem, size_t length)
{
	hexdump_to(stderr, mem, length);
}