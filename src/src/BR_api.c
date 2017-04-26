#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "HRIR.h"
#include "BR_api.h"
#include "BR_core.h"
#include "common.h"
#include "define.h"

/**
 *  * Defines 3D Audio Rendering Object 
 */

int AudioRendering(int f_length)
{
    if(f_length <= 0)	return -1;      //ERR

    printf("This is f_length: %5d\n",f_length);
    AudioRenderCore();
    return 0;           //No ERR
}

int AudioRenderingCreate(const int sampleRate, const int frameSize, RENDER_HANDLE *handle)
{
	AUDIO_RENDERING_INFO *info;

	if(handle == NULL)
	{
		return -1; //ERR
	}

	/* init */
	info = NULL;
	info = (AUDIO_RENDERING_INFO *) malloc (sizeof(AUDIO_RENDERING_INFO));
	if(info == NULL)
	{
		return -2; //ERR
	}
	memset (info, 0x00, sizeof(AUDIO_RENDERING_INFO));

	if(sampleRate > MAX_SAMPLE_RATE)
	{
		free(info);
		return -3;
	}
	info->sampleRate = sampleRate;

	if(frameSize > MAX_FRAME_SIZE)
	{
		free(info);
		return -4;
	}
	info->frameSize = frameSize; 
	info->channels = 2;
	info->filterSize = HRIR_FILTER_SIZE;
	info->elevation = 0;
	info->azimuth = 0;
	info->distance = 1;
	info->filterIndex = 72;
	
	*handle = info;
	return 0; //No ERR
}


int AudioRenderingExec(RENDER_HANDLE handle, const int elevation, const int azimuth, int distance,
        const short *inputBuffer, short *outLBuffer, short *outRBuffer)
{
	int errCode;
	
	if(handle == NULL)	return -1;	//ERR
	
	int elevationIndex;
	AUDIO_RENDERING_INFO *info;
	info = (AUDIO_RENDERING_INFO *)handle;
	int filterIndex = 72;
	int elevationQuant;
	int azimuthQuant;
	
	//Cordinate adaptation
	errCode = ConvertCordinate(elevation, azimuth, &elevationQuant, &azimuthQuant);
	if(errCode != 0)	return -2;	//ERR 

	printf("[Ele]: %d > %d\n",elevation, elevationQuant);
	printf("[Azi]: %d > %d\n",azimuth, azimuthQuant);
	//Filter index selection
	/*
	if((info->elevation != elevationQuant) ||(info->azimuth != azimuthQuant))
		errCode = GetFilterIndex(elevationQuant, azimuthQuant, &filterIndex);
	else
		filterIndex = info->filterIndex;
	*/
	//Filtering, History buffer update
	

	//Update parameters
	info->elevation = elevationQuant;
	info->azimuth = azimuthQuant;
	info->filterIndex = filterIndex;
	return 0;
}

int AudioRenderingDestroy(RENDER_HANDLE handle)
{
	if(handle == NULL)	return -1;	//ERR

	AUDIO_RENDERING_INFO *info;
	info = (AUDIO_RENDERING_INFO *)handle;

	if(info != NULL)	free(info);
	return 0;	//No ERR
}
