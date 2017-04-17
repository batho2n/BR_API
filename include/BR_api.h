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

int AudioRenderingExec(RENDER_HANDLE *handle);
int AudioRenderingCreate(RENDER_HANDLE *handle);
int AudioRenderingDestroy(RENDER_HANDLE *handle);

#endif
