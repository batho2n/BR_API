#include <stdio.h>
#include <math.h>

#include "HRIR.h"
#include "BR_api.h"
#include "BR_core.h"
#include "common.h"


/**
 *  * Defines 3D Audio Rendering Object 
 */
typedef struct _AUDIO_RENDERING_INFO_ 
{
	int sampleRate;
	
	int frameSize;
	int maxFrameSize;
	
	int channels;
	
	short *in;

}AUDIO_RENDERING_INFO;


int AudioRendering(int f_length)
{
    int i;
    if(f_length <= 0)
    {
        return -1;      //ERR
    }

    printf("This is f_length: %5d\n",f_length);
    
    AudioRenderCore();

    return 0;           //No ERR
}

int AudioRenderingCreate(RENDER_HANDLE *handle)
{
	AUDIO_RENDERING_INFO *info;
	int err;

	err = 0;

	if(handle == NULL)
	{
		return -1;		//Err
	}

	/* init */
	info = (AUDIO_RENDERING_INFO *) malloc (sizeof(AUDIO_RENDERING_INFO));
	if(info == NULL)
	{
		return -2;
	}

	memset (info, 0x00, sizeof(AUDIO_RENDERING_INFO));

	info->sampleRate = 44100;

	return err;
}


int AudioRenderingExec(RENDER_HANDLE *handle)
{
	AUDIO_RENDERING_INFO *info;
	int err;

	err = 0;

	return err;
}

int AudioRenderingDestroy(RENDER_HANDLE *handle)
{
	AUDIO_RENDERING_INFO *info;
	int err;

	err = 0;

	return err;
}
