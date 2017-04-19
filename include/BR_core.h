/**
* @file     BR_core.h
* @brief    BR core function
* @author   batho2n
* @date     2017-04-01
*
* Copyright (C) 2017 batho2n
* All Right Reserved
*/

#include <stdlib.h>
#include "define.h"
#ifndef __BR_CORE_H__
#define __BR_CORE_H__

typedef struct _AUDIO_RENDERING_INFO_ 
{
	int sampleRate;
	int frameSize;
	int channels;
	int filterSize;

	int elevation;
	int azimuth;
	int distance;
	
	int filterIndex;

	float preLBuffer[PRE_BUFFER_SIZE];
	float preRBuffer[PRE_BUFFER_SIZE];

}AUDIO_RENDERING_INFO;


int AudioRenderCore();

int GetElevationIndex(const int elevation, int *index);
int DegreeQuant(int degree);
int ConvertCordinate(const int elevation, const int azimuth, int *elevationQuant, int *azimuthQuant);
#endif
