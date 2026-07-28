#include "sav/init/savTreeInit/savTreeInit.h"
#include "sav/init/savTreeVerify/savTreeVerify.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>




/**
 * Note: these functions rely on macros found in the savTreeInit.h file.
 * It is important to eventually seperate those macros into their own .h file.
 */

bool savTreeDirVerify(void){ //TODO: properly comment both functions :/
    struct stat st;
    static const char *subdir[] = SUBDIR_PATHS;

    size_t totalDirs = sizeof(subdir) / sizeof(subdir[0]);

    for(size_t i = 0; i < totalDirs; i++){
        if (stat(subdir[i], &st) != 0){
            perror(subdir[i]);
            return false;
        }

        if(S_ISDIR(st.st_mode) == 0){
            fprintf(stderr, "%s is not a directory.\n", subdir[i]);
            return false;
        }
    }

    return true;
}

bool savTreePermVerify(void){
    struct stat st;
    static const char *subdir[] = SUBDIR_PATHS;

    size_t totalDirs = sizeof(subdir) / sizeof(subdir[0]);

    for(size_t i = 0; i < totalDirs; i++){
        if (stat(subdir[i], &st) != 0){
            perror(subdir[i]);
            return false;
        }

        if((st.st_mode & 0777) != DIR_PERMS){
            if(chmod(subdir[i], DIR_PERMS) == -1){
                perror(subdir[i]);
                return false;
            }
        }

    }
    
    return true;
}