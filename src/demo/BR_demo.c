#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "BR_api.h"
#include "common.h"
#include "define.h"


void Usage(char *argv)
{
    fprintf(stderr,"\nUsage of %s : <input mono file> <output streo file> [options]\n", argv);
    fprintf(stderr,"[options]\n");
    fprintf(stderr,"    -i  : Input mono wav file\n");
    fprintf(stderr,"    -o  : Output stereo raw file\n");
    fprintf(stderr,"    -a  : Azimuth -180 ~ 180, 0 is forward, [default 0]\n");
    fprintf(stderr,"    -e  : Elevation -90 ~ 90, 0 is forward, [default 0]\n");
    fprintf(stderr,"    -d  : Distance 1 ~ 5, 1 is nearest, [default 1]\n");
    fprintf(stderr,"    -s  : Frame size < 20 (msec), [default 10]\n");
    fprintf(stderr,"    -h  : Show usage of %s\n", argv);
}


int main(int argc, char **argv)
{
    if(argc < 5)
    {
        Usage(argv[0]);
        return 0;
    }

    char inFileName[256];
    char outFileName[256];
    int azimuth = 0;
    int elevation = 0;
    int distance = 1;
   	int frameSizeTime = 10;
	
    int errCode;
    int args = 1;

    for(;args<argc;args++)
    {
        if(argv[args][0] == '-')
            switch (argv[args][1])
            {
                case 'i':
                    args++;
    				strcpy(inFileName,argv[args]);
                    break;
                case 'o':
                    args++;
    				strcpy(outFileName,argv[args]);
                    break;
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
                case 's':
                    args++;
                    frameSizeTime = atoi(argv[args]);
                    break;
                default:
                    Usage(argv[0]);
                    break;
            }
    }

	
    //Memory Allocation of input/output files
    /* Wav Open and Header Read */
	FILE *inFile = fopen(inFileName, "rb");
	FILE *outFile= fopen(outFileName,"wb");

	WAV_HEADER inHeader;
	if(inFile == NULL)	return 0;	//ERR
	else				fread(&inHeader, 1, sizeof(WAV_HEADER),inFile);
	
	if(outFile == NULL) return 0;	//ERR

	int sampleRate = inHeader.sampleRate;
	int numChannels= inHeader.numChannels;
			
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

    //Rendering the signal(short time buffer processing)
    //3D Audio Rendering
	printf("Audio Rendering API Demo Program\n");
	short inputBuffer[MAX_FRAME_SIZE];
	short outLBuffer[MAX_FRAME_SIZE];
	short outRBuffer[MAX_FRAME_SIZE];
	
	int cnt=0;
	int frameSize = (int)(floor(sampleRate*frameSizeTime/1000.0));
	
	RENDER_HANDLE info;
	errCode = AudioRenderingCreate(sampleRate, frameSize, &info);
	if(errCode != 0)	return 0; 	//ERR
	printf("API Create Success\n");

	while(frameSize == (int)fread(inputBuffer,sizeof(short),frameSize,inFile))
	{
		errCode = AudioRenderingExec(info, elevation, azimuth, distance, inputBuffer, outLBuffer, outRBuffer);
		if(errCode !=0) return 0;

		errCode = StereoPcmWrite(outLBuffer, outRBuffer, frameSize, outFile);
		if(errCode != 0) return 0;		//ERR
		cnt++;
	}
	printf("API Execution Success\n");
    //Output Wave Check Clipping
    //Output Wave writing

    //Memory destroy
	//
	errCode = AudioRenderingDestroy(info);
	if(errCode != 0)	return 0; 	//ERR
	fclose(inFile);
	fclose(outFile);

	printf("API Destroy Success\n");
	printf("Finish Audio Rendering\n");
    return 0;
}
