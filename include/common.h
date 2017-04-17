/**
* @file     common.h
* @brief    Common functions
* @author   batho2n
* @date     2017-04-01
*
* Copyright (C) 2017 batho2n
* All Right Reserved
*/

#include <stdint.h>

#ifndef __COMMON_H__
#define __COMMON_H__

typedef struct _WAV_HEADER_
{
    char     chunkId[4];
    uint32_t chunkSize;
    char     format[4];
    char     fmtchunkId[4];
    uint32_t fmtchunkSize;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bps;
    char     datachunkId[4];
    uint32_t datachunkSize;
}WAV_HEADER;

void ErrMessage(int i);

int GetFileSize(const char *fileName, int *size);

int StereoPcmWrite(const short *lBuffer, const short *RBuffer,int size, FILE *file);

#endif
