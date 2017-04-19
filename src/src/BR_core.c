#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "BR_core.h"
#include "define.h"

int GetElevationIndex(const int elevation, int *index)
{
	if(elevation == NULL)	return -1;	//ERR

	return 0;	//No ERR
}

int DegreeQuant(const int degree)
{
	if(degree > 352)	return 0;
	int degQ = (degree>0)?((degree + 7)/DEG_QUANT):((degree - 7)/DEG_QUANT);
	return degQ * DEG_QUANT;
}

int ConvertCordinate(const int elevation, const int azimuth,
		int *elevationQuant, int *azimuthQuant)
{
	if((elevation == NULL)||(azimuth==NULL))	return -1;	//ERR
	if((elevation > MAX_ELEVATION)||(elevation < MIN_ELEVATION))	return -2; 	//ERR
	if((azimuth > MAX_AZIMUTH)||(azimuth < MIN_AZIMUTH))			return -3; 	//ERR

	//Change input direction information
	*elevationQuant = DegreeQuant(elevation);
	*azimuthQuant = DegreeQuant(azimuth);

	return 0;	//No ERR
}

int AudioRenderCore()
{
    printf("AudioRenderer is called\n");
    return 0;
}
