#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>

#include "common.h"
#include "define.h"

void ErrMessage(int i)
{
	printf("[Err]: %d\n",i);
	exit(1);
}
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


int StereoPcmWrite(const short *lBuffer, const short *rBuffer,int size, FILE *file)
{
	if((lBuffer == NULL) || (rBuffer == NULL))
	{
		return -1;
	}
	if((size > MAX_FRAME_SIZE) ||(size <= 0))
	{
		return -2;
	}
	if(file == NULL)
	{
		return -3;
	}

	short outBuffer[MAX_FRAME_SIZE*2];
    
    int i;
	for(i=0;i<size;i++)
	{
		outBuffer[i*2]  = lBuffer[i];
		outBuffer[i*2+1]= rBuffer[i];
	}
	
	return size*2 == (int)fwrite(outBuffer,sizeof(short),size*2,file)? 0: -4;
}

