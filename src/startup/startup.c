#include <startup/startup.h>
#include <sav/savTreeInit/savTreeInit.h>

void startup(void){

    //NOTE: will eventually replace with dedicated save system init function
    createSavTree();

}