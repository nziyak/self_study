#include <stdio.h>
#include <stdlib.h>

int main() 
{
    const char* sourceFileName = "example.c"; //name of the c file to be compiled
    const char* targetExecutable = "example"; //name of the executable to be runned

    //create compile command
    char compileCommand[100];
    snprintf(compileCommand, sizeof(compileCommand), "gcc %s -o %s", sourceFileName, targetExecutable);

    int compileResult = system(compileCommand); //run compile command

    if (compileResult == 0) //if the source file compiled succesfully, run the executable
    {
        printf("compilation finished succesfully. created executable is being running...\n");

        char runCommand[50];
        snprintf(runCommand, sizeof(runCommand), """./%s""", targetExecutable); //create run command
        int executeResult = system(runCommand); //run the executable

        if (executeResult != 0) printf("Executable could not been runned.\n");
    } 

    else printf("compilation is unsuccesful.\n");

    return 0;
}
