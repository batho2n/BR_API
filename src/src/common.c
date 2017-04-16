#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>

#include "common.h"

typedef strut _WAV_HEADER_
{
    char     chunk_id[4];
    uint32_t chunk_size;
    char     format[4];
    char     fmtchunk_id[4];
    uint32_t fmtchunk_size;
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bps;
    char     datachunk_id[4];
    uint32_t datachunk_size;
}WAV_HEADER;


int FileGetSize (const char *fileName, int *size)
{
	struct stat fs;
	int n;

	if (fileName == NULL || (fileName != NULL && fileName[0] == 0x00)) {
		return -1; /* ERR */
	}

	if (size == NULL) {
	return -2; /* ERR */
	}

	n = stat (fileName, &fs);
	if (n != 0) {
		return -3; /* ERR */
	}

	*size = (int) fs.st_size;

	return 0; /* NOERR */
}

