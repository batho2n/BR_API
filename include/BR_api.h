/**
* @file     BR_api.h
* @brief    Bianural Renderer API
* @author   batho2n
* @date     2017-04-01
*
* Copyright (C) 2017 batho2n
* All Right Reserved
*/

#ifndef __BR_API_H__
#define __BR_API_H__

typedef void *RENDER_HANDLE;

int AudioRendering(int f_length);

int AudioRenderingCreate(const int sampleRate, const int frameSize,  RENDER_HANDLE *handle);
int AudioRenderingExec(RENDER_HANDLE handle, const int elevation, const int azimuth,  const short *inputBuffer, short *outLBuffer, short *outRBuffer);

int AudioRenderingDestroy(RENDER_HANDLE handle);

#endif
