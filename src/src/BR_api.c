#include <stdio.h>
#include <math.h>

#include "HRIR.h"
#include "BR_api.h"

int AudioRendering(int f_length)
{
    int i;
    if(f_length <= 0)
    {
        return -1;      //ERR
    }

    printf("This is f_length: %5d\n",f_length);
    
    for(i=0;i<10;i++)
    {
        printf("[%02d]: %d\n",i, ele[i]);
    }

    return 0;           //No ERR
}
