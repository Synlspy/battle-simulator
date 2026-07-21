#include <startup/startup.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

void startup(void){

    //FIXME: add error checking
    mkdir("sav", 0777);
    mkdir("sav/sav1", 0777);
    mkdir("sav/sav2", 0777);
    mkdir("sav/sav3", 0777);

}