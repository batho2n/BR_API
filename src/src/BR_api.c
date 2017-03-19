#include <stdio.h>
#include <math.h>

#include "BR_api.h"

int AudioRendering(int f_length)
{

    if(f_length <= 0)
    {
        return -1;      //ERR
    }

    printf("This is f_length: %5d\n",f_length);


    return 0;           //No ERR
}
