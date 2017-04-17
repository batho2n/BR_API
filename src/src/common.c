#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>

#include "common.h"


int GetFileSize (const char *fileName, int *size)
{
	struct stat fs;
	int n;

	if (fileName == NULL || (fileName != NULL && fileName[0] == 0x00))
	{
		return -1; // ERR
	}

	if (size == NULL) 
	{
		return -2; // ERR
	}

	n = stat (fileName, &fs);
	if (n != 0) 
	{
		return -3; // ERR
	}

	*size = (int) fs.st_size;

	return 0; // No ERR
}


