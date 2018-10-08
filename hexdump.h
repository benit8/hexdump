/*
** EPITECH PROJECT, 2018
** HexDump
** File description:
** HexDump header file
*/

#ifndef HEXDUMP_H_
#define HEXDUMP_H_

////////////////////////////////////////////////////////////////////////////////

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////

#define HEXDUMP_SKIP_DUPLICATES

#define HEXDUMP_COL_SIZE	8
#define HEXDUMP_COL_COUNT	2

#define HEXDUMP_ROW_LENGTH	(HEXDUMP_COL_COUNT * HEXDUMP_COL_SIZE)

////////////////////////////////////////////////////////////////////////////////

void hexdump(void *mem, size_t length);
void hexdump_to(FILE *stream, void *mem, size_t length);

////////////////////////////////////////////////////////////////////////////////

#endif