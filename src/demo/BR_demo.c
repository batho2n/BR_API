#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "BR_api.h"
#include "common.h"
#include "define.h"

void Usage(char *argv)
{
    fprintf(stderr,"\nUsage of %s : <input mono file> <output streo file> [options]\n", argv);
    fprintf(stderr,"[options]\n");
    fprintf(stderr,"    -a  : Azimuth -180 ~ 180, 0 is forward, [default 0]\n");
    fprintf(stderr,"    -e  : Elevation -90 ~ 90, 0 is forward, [default 0]\n");
    fprintf(stderr,"    -d  : Distance 1 ~ 5, 1 is nearest, [default 1]\n");
    fprintf(stderr,"    -h  : Show usage of %s\n", argv);
}


int main(int argc, char **argv)
{
    if(argc < 3)
    {
        Usage(argv[0]);
        return 0;
    }

    char inFileName[256];
    char outFileName[256];
    int azimuth = 0;
    int elevation = 0;
    int distance = 3;
    
    int errCode;
    int args = 1;
    strcpy(inFileName,argv[args++]);
    strcpy(outFileName,argv[args++]);

    for(;args<argc;args++)
    {
        if(argv[args][0] == '-')
            switch (argv[args][1])
            {
                case 'a':
                    args++;
                    azimuth = atoi(argv[args]);
                    break;
                case 'e':
                    args++;
                    elevation = atoi(argv[args]);
                    break;
                case 'd':
                    args++;
                    distance = atoi(argv[args]);
                    break;
                default:
                    Usage(argv[0]);
                    break;
            }
    }

	
	//errCode = AudioRendering(5);
	if(errCode != 0)
    {
        fprintf(stderr,"[Err:%d] Error\n",errCode);
        return 0;
    }

	int fileSize;

    //Memory Allocation of input/output files
    /* Wav Open and Header Read */
	FILE *inFile = fopen(inFileName,"rb");
	WAV_HEADER header;
	if(inFile == NULL)	return 0;
	else				fread(&header, 1, sizeof(WAV_HEADER),inFile);
	
	int sampleRate = header.sampleRate;
	int numChannels= header.numChannels;
	
	if(sampleRate > MAX_SAMPLE_RATE)
	{
		printf("[Err]Sample Rate must be under %d Hz\n", MAX_SAMPLE_RATE);
		return 0;
	}
	if(numChannels != 1)
	{
		printf("[Err]Input signal must be mono signal\n");
		return 0;
	}

	

    //Azimuth and elevation recalculating

	RENDER_HANDLE info;

    //Rendering the signal(short time buffer processing)
    //3D Audio Rendering
	printf("AudioRendering\n");
	AudioRendering(azimuth);

    //Output Wave Check Clipping
    //Output Wave writing


    //Memory destroy
    return 0;
}
