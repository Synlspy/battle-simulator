#include "sav/savTreeInit/savTreeInit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>

bool createSavTree(void){
    static const char *subdir[] = {"sav/sav1", "sav/sav2", "sav/sav3"};

    //check if root sav folder exists
        if(mkdir("sav", 0755) == -1 && errno != EEXIST){
            perror("Error: Couldn't create root 'sav' folder");
            return false;
        }

    size_t totalDirs = sizeof(subdir) / sizeof(subdir[0]);

    //only loop through folder creation if folder doesn't already exist
    for(size_t i = 0; i < totalDirs; i++){
        
        if(mkdir(subdir[i], 0755) == -1 && errno != EEXIST){
            perror(subdir[i]);
            return false;
        }
    }
    return true;
}
