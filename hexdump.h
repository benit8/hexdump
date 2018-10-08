/*
** EPITECH PROJECT, 2018
** HexDump
** File description:
** HexDump header file
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////

#define HEXDUMP_COL_SIZE	8
#define HEXDUMP_COL_COUNT	2
#define HEXDUMP_ROW_LENGTH	(HEXDUMP_COL_COUNT * HEXDUMP_COL_SIZE)

#define HEXDUMP_SKIP_DUPLICATES

////////////////////////////////////////////////////////////////////////////////

void hexdump(void *mem, size_t length);
void hexdump_to(FILE *stream, void *mem, size_t length);