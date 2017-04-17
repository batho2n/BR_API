/**
* @file     define.h
* @brief    define for BR_API
* @author   batho2n
* @date     2017-04-017
*
* Copyright (C) 2017 batho2n
* All Right Reserved
*/

#ifndef __DEFINE_H__
#define __DEFINE_H__



#define MAX_SAMPLE_RATE			44100
#define MAX_FRAME_SIZE			(int)(MAX_SAMPLE_RATE * 20/1000)

#define HRIR_FILTER_SIZE		512
#define PRE_BUFFER_SIZE			HRIR_FILTER_SIZE
#endif
