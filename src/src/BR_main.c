#include <stdio.h>
#include <string.h>



void Usage(char *argv)
{
    fprintf(stderr,"\nUsage of %s : <input mono file> <output streo file> [options]\n", argv);
    fprintf(stderr,"[options]\n");
    fprintf(stderr,"    -a  : Azimuth -180 ~ 180, 0 is forward, [default 0]\n");
    fprintf(stderr,"    -e  : Elevation -90 ~ 90, 0 is forward, [default 0]\n");
    fprintf(stderr,"    -d  : Distance 1 ~ 5, 1 is nearest, [default 1]\n");

    exit 0;
}



int main(int argc, char **argv)
{
    if(argc < 3)
    {
        Usage(argv[0]);
    }

    char inputFname[256];
    char outputFname[256];
    int azimuth = 0;
    int elevation = 0;
    int distance = 3;

    int args = 1;
    strcpy(inputFname,argv[args++]);
    strcpy(outputFname,argv[args++]);

    for(;args<argc;args++)
    {
        if(argv[args][0] == '-')
            switch (argv[args][1])
                case 'a':
                    break;
                case 'e':
                    break;
                case 'd':
                    break;
                default:
                    Usage(argv[0]);

                    break;

    }

    //Memory Allocation of input/output files
    //Input Wave Read

    //Azimuth and elevation recalculating

    //Rendering the signal(short time buffer processing)
    //3D Audio Rendering


    //Output Wave Check Clipping
    //Output Wave writing


    //Memory destroy
    return 0;
}
