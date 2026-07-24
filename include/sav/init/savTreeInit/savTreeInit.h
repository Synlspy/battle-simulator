#ifndef SAVTREEINIT_H
#define SAVTREEINIT_H

/**
 * @file savTreeInit.h
 * @brief Handles the initial creation of the save directory tree
 *  */

#include <stdbool.h>

/**
 * @brief Default permissions for created directories (rwxr-xr-x)
 * Standard on POSIX systems. It gives the owner write/read/execute permissions and group/others read/execute permissions
 */

#define DIR_PERMS 0755

/**
 * @brief Creates the save directory tree.
 * This function creates/initializes the "sav/" directory, as well as the subsequent "sav/sav1/", "sav/sav2/", and "sav/sav3/" directories
 * 
 * @note Only handles creation. Use the suite of verification functions found in savTreeVerify.h
 * 
 * @return true if the function completes without any errors.
 * @return false if the function fails with errors.
 */

bool createSavTree(void);

#endif //SAVTREEINIT_H
