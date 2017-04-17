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
typedef struct _AUDIO_RENDERING_INFO_ 
{
	int sampleRate;
	int frameSize;
	int channels;
	int filterSize;

	int elevation;
	int azimuth;
	int distance;
	
	float preLBuffer[PRE_BUFFER_SIZE];
	float preRBuffer[PRE_BUFFER_SIZE];

}AUDIO_RENDERING_INFO;


int AudioRendering(int f_length)
{
    if(f_length <= 0)	return -1;      //ERR

    printf("This is f_length: %5d\n",f_length);
    AudioRenderCore();
    return 0;           //No ERR
}

int AudioRenderingCreate(int sampleRate, int frameSize, int elevation, int azimuth, int distance,
		RENDER_HANDLE *handle)
{
	AUDIO_RENDERING_INFO *info;

	if(handle == NULL)
	{
		return -1; //ERR
	}

	/* init */
	info = (AUDIO_RENDERING_INFO *) malloc (sizeof(AUDIO_RENDERING_INFO));
	if(info == NULL)
	{
		return -2; //ERR
	}
	memset (info, 0x00, sizeof(AUDIO_RENDERING_INFO));

	info->sampleRate = sampleRate;
	info->frameSize = frameSize;
	info->channels = 2;
	info->filterSize = HRIR_FILTER_SIZE;
	info->elevation = elevation;
	info->azimuth = azimuth;
	info->distance = distance;

	*handle = info;
	return 0; //No ERR
}


int AudioRenderingExec(RENDER_HANDLE handle, short *inputBuffer, short *outLBuffer, short *outRBuffer)
{
	if(handle == NULL)	return -1;	//ERR

	AUDIO_RENDERING_INFO *info;
	info = (AUDIO_RENDERING_INFO *)handle;

	//Filtering
	//
	//Pre BUFFER update

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
