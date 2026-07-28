#include <stdbool.h>
#include <stdio.h>
#include <sav/init/savTreeInit/savTreeInit.h>
#include "sav/init/savTreeVerify/savTreeVerify.h"

bool savSysInit(void){

    if(createSavTree() == false){
        fprintf(stderr, "Error creating save tree.\n");
        return false;
    }
    if(savTreeDirVerify() == false){
        fprintf(stderr, "Error verifying save directories.\n");
        return false;
    }
    if(savTreePermVerify() == false){
        fprintf(stderr, "Error verifying save directory permissions.\n");
    }

    return true;
}