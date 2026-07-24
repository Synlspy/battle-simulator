#include "sav/init/savTreeInit/savTreeInit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>


//Note: This function does not verify the integrity of the save tree. It only creates it.
//The function that verifies the save tree is defined as savTreePermVerify() in savTreeVerify.h

//The DIR_PERMS macro is defined in savTreeInit.h as 0755

bool createSavTree(void){

    static const char *subdir[] = {"sav/sav1", "sav/sav2", "sav/sav3"};

    if(mkdir("sav", DIR_PERMS) == -1){
        if(errno != EEXIST){ //Excludes EEXIST because it would trigger false errors and exit after the first run
            perror("sav");
            return false;
        }
               
    }

    size_t totalDirs = sizeof(subdir) / sizeof(subdir[0]);

    for(size_t i = 0; i < totalDirs; i++){
        
        if(mkdir(subdir[i], DIR_PERMS) == -1){
            if(errno != EEXIST){
                perror(subdir[i]);
                return false;
            }
            
        }

    }
    return true;
}