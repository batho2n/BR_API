#include <stdio.h>
#include <math.h>

#include "HRIR.h"
#include "BR_api.h"
#include "BR_core.h"
#include "common.h"

int AudioRendering(int f_length)
{
    int i;
    if(f_length <= 0)
    {
        return -1;      //ERR
    }

    printf("This is f_length: %5d\n",f_length);
    
    WaveRead();
    AudioRenderCore();

    return 0;           //No ERR
}
