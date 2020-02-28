/*
LAB2 Project for SOFE 3950U
CRN : 74092
Group Members: Devorah Jane Coralde(100660214), Ramin Sami (100655257), Zainab Rehan (100653955)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"

// functions to call through myshell.c 

void pauseShell(){
	
	// While loop to check if the enter key hasn't been pressed, sleep while it hasn't    
	while(getchar() != '\n'){
		printf("%s\n","Paused ...");
		sleep(2);
    }
}

void helpManual(){
    // Lists all the command
    printf("Commands Available:   \n");
    printf("echo: prints to screen\n");
    printf("pause: pauses command shell\n");
    printf("quit: exits shell\n");
    printf("cd: changes directory\n");
    printf("clr: clears screen\n");
    printf("dir: displays contents of directory\n");
    printf("environ: displays all environments\n\n");
}

void listEnv(){
    // state environments on the user path
    // gentenv () searches the environment list to find the environment variable <name>, and returns a pointer to the corresponding <value> string.
    printf("PATH : %s\n", getenv("PATH"));
}

void clear(){
    //print 50 lines and clear screen
    for(int i=0; i< 50; i++){
        printf("\n");
    }
}
