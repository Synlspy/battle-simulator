#include "sav/savTreeInit/savTreeInit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>


//THIS CODE DOES NOT HANDLE VERIFYING FOLDER PERMISSIONS AT RUNTIME!
//THAT IS DONE IN THE 'savTreeVerify()' FUNCTION

//The DIR_PERMS macro is defined in savTreeInit.h as 0755

bool createSavTree(void){
    static const char *subdir[] = {"sav/sav1", "sav/sav2", "sav/sav3"};

    //check if root sav folder exists

    if(mkdir("sav", DIR_PERMS) == -1){
        if(errno != EEXIST){
            perror("sav");
            return false;
        }
               
    }

    size_t totalDirs = sizeof(subdir) / sizeof(subdir[0]);

    //attempt to create each directory

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