# HexDump
Simple C functions that replicates the behaviour of the `hexdump -C` command

## Usage
HexDump comes with two functions:
```C
void hexdump(void *mem, size_t length);
void hexdump_to(FILE *stream, void *mem, size_t length);
```
Pass a pointer to your data and its length to both functions. The first one dumps to `stderr` meanwhile the other let you provide a stream to dump to.

## Customizability
Through `#define`s in the [header file](hexdump.h), you can:
- Skip or not duplicate lines
- Set the number of columns
- Set the number of bytes per column

## Differences
There's actually a difference between this hexdump and the original one: this one separates the ASCII dump in columns to match the hex dump's number of columns. I feel like it enhances data readability.

## TL;DR
Here's what it looks like, with 3 columns of 4 bytes each:
```
$> ./hexdump main.c
00000000  2f 2a 0d 0a  2a 2a 20 45  50 49 54 45  |/*..|** E|PITE|
0000000c  43 48 20 50  52 4f 4a 45  43 54 2c 20  |CH P|ROJE|CT, |
00000018  32 30 31 38  0d 0a 2a 2a  20 48 65 78  |2018|..**| Hex|
00000024  44 75 6d 70  0d 0a 2a 2a  20 46 69 6c  |Dump|..**| Fil|
00000030  65 20 64 65  73 63 72 69  70 74 69 6f  |e de|scri|ptio|
0000003c  6e 3a 0d 0a  2a 2a 20 45  78 61 6d 70  |n:..|** E|xamp|
00000048  6c 65 20 6d  61 69 6e 20  66 75 6e 63  |le m|ain |func|
00000054  74 69 6f 6e  0d 0a 2a 2f  0d 0a 0d 0a  |tion|..*/|....|
00000060  23 69 6e 63  6c 75 64 65  20 22 68 65  |#inc|lude| "he|
0000006c  78 64 75 6d  70 2e 68 22  0d 0a 0d 0a  |xdum|p.h"|....|
00000078  69 6e 74 20  6d 61 69 6e  28 69 6e 74  |int |main|(int|
00000084  20 61 63 2c  20 63 68 61  72 20 2a 61  | ac,| cha|r *a|
00000090  76 5b 5d 29  0d 0a 7b 0d  0a 09 69 66  |v[])|..{.|..if|
0000009c  20 28 61 63  20 21 3d 20  32 29 0d 0a  | (ac| != |2)..|
000000a8  09 09 72 65  74 75 72 6e  20 45 58 49  |..re|turn| EXI|
000000b4  54 5f 46 41  49 4c 55 52  45 3b 0d 0a  |T_FA|ILUR|E;..|
000000c0  0d 0a 09 46  49 4c 45 20  2a 66 70 20  |...F|ILE |*fp |
000000cc  3d 20 66 6f  70 65 6e 28  61 76 5b 31  |= fo|pen(|av[1|
000000d8  5d 2c 20 22  72 22 29 3b  0d 0a 09 69  |], "|r");|...i|
000000e4  66 20 28 21  66 70 29 0d  0a 09 09 72  |f (!|fp).|...r|
000000f0  65 74 75 72  6e 20 45 58  49 54 5f 46  |etur|n EX|IT_F|
000000fc  41 49 4c 55  52 45 3b 0d  0a 0d 0a 09  |AILU|RE;.|....|
00000108  66 73 65 65  6b 28 66 70  2c 20 30 2c  |fsee|k(fp|, 0,|
00000114  20 53 45 45  4b 5f 45 4e  44 29 3b 0d  | SEE|K_EN|D);.|
00000120  0a 09 73 69  7a 65 5f 74  20 6c 65 6e  |..si|ze_t| len|
0000012c  67 74 68 20  3d 20 66 74  65 6c 6c 28  |gth |= ft|ell(|
00000138  66 70 29 3b  0d 0a 09 66  73 65 65 6b  |fp);|...f|seek|
00000144  28 66 70 2c  20 30 2c 20  53 45 45 4b  |(fp,| 0, |SEEK|
00000150  5f 53 45 54  29 3b 0d 0a  0d 0a 09 75  |_SET|);..|...u|
0000015c  69 6e 74 38  5f 74 20 64  61 74 61 5b  |int8|_t d|ata[|
00000168  6c 65 6e 67  74 68 5d 3b  0d 0a 09 6d  |leng|th];|...m|
00000174  65 6d 73 65  74 28 64 61  74 61 2c 20  |emse|t(da|ta, |
00000180  30 2c 20 6c  65 6e 67 74  68 29 3b 0d  |0, l|engt|h);.|
0000018c  0a 0d 0a 09  69 66 20 28  66 72 65 61  |....|if (|frea|
00000198  64 28 64 61  74 61 2c 20  73 69 7a 65  |d(da|ta, |size|
000001a4  6f 66 28 75  69 6e 74 38  5f 74 29 2c  |of(u|int8|_t),|
000001b0  20 6c 65 6e  67 74 68 2c  20 66 70 29  | len|gth,| fp)|
000001bc  20 21 3d 20  6c 65 6e 67  74 68 29 20  | != |leng|th) |
000001c8  7b 0d 0a 09  09 66 63 6c  6f 73 65 28  |{...|.fcl|ose(|
000001d4  66 70 29 3b  0d 0a 09 09  72 65 74 75  |fp);|....|retu|
000001e0  72 6e 20 45  58 49 54 5f  46 41 49 4c  |rn E|XIT_|FAIL|
000001ec  55 52 45 3b  0d 0a 09 7d  0d 0a 0d 0a  |URE;|...}|....|
000001f8  09 68 65 78  64 75 6d 70  5f 74 6f 28  |.hex|dump|_to(|
00000204  73 74 64 6f  75 74 2c 20  64 61 74 61  |stdo|ut, |data|
00000210  2c 20 6c 65  6e 67 74 68  29 3b 0d 0a  |, le|ngth|);..|
0000021c  0d 0a 09 66  63 6c 6f 73  65 28 66 70  |...f|clos|e(fp|
00000228  29 3b 0d 0a  09 72 65 74  75 72 6e 20  |);..|.ret|urn |
00000234  45 58 49 54  5f 53 55 43  43 45 53 53  |EXIT|_SUC|CESS|
00000240  3b 0d 0a 7d                            |;..}|
00000244
```
