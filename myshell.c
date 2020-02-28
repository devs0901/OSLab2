/*
LAB2 Project for SOFE 3950U
CRN Number:  74024
Group Members: Devorah Jane Coralde (100660214), Ramin Sami (100655257), Zainab Rehan (100653955)
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

#define BUFFER_LEN 256

//Define functions in myshell.h 
FILE * stream(FILE * f){
	//if statement to check if file exists
	if(f != NULL){
		return f;
	}
	else{
		return stdin;
	}	
}

//Main function
int main(int argc, char *argv[]){

    // Input buffer && commands
    char buffer[BUFFER_LEN] = {0};
    char command[BUFFER_LEN] = {0};

    // 2d-array for arg
    char args[BUFFER_LEN][BUFFER_LEN] = {{0}};

    // Declare cwd
	// cwd is most natural form for the current architecture, identical to ‘pwd’
    char cwd[1024];
    FILE *fp;

    // If shell script is given
    if(argc >= 2){
        if(strstr(argv[1], ".sh") != NULL){
            fp = fopen(argv[1], "r");
        }
    }

    // Task 6 - Output the working or current directory
    // getcwd() is used to get the current working directory on the specified drive.
    printf("%s$ ", getcwd(cwd, sizeof(cwd)));

    // While loop to get command input from user infinitely
    while (fgets(buffer, BUFFER_LEN, stream(fp)) != NULL){
    
    // String tokenization for command and argument
    // Command
    char* token = strtok(buffer, " ");
    strcpy(command, token);

    // Arguments
    int numWords = 0;
    
    // Check if token is not null
    while(token != NULL){
      token = strtok(NULL, " ");
      
      // If statement to perform funtion with token
      if (token != NULL){
      	strcpy(args[numWords], token);
      	numWords++;
	  }
	}
	
	// Take line out of argument array
	for(int i=0; i<numWords; i++){
		for(int j=0; j <strlen(args[i]); j++){
			if(args[i][j] == '\n' || args[i][j] == '\0'){
				args[i][j] = NULL;
			}
		}
	}
      
	// Task 2 - Interpret the input as program invocation.
	// Checks that the input is a command and execute
 
	if (strcmp(command, "cd") == 0 || strcmp(command, "cd\n") == 0){
    
		// Input cd : change the directory
    	// Interpretation: changeDir(args, cwd);

    	// If there is no input, state the current directory
    	if(strlen(args[0]) <=0){
        	printf("PWD: %s\n", getcwd(cwd, sizeof(cwd)));
    	} 
    
		else{
			// If the directory is stated otherwise change it.
			// chdir() is used to cause the directory named by the <pathname> pointed to by the <path> argument to become the working directory.
			if(chdir(args[0])< 0){
				fputs("Directory not found\n", stderr);
			}
			else{
				chdir(args[0]);
				printf("Directory: %s\n", getcwd(cwd, sizeof(cwd)));
           }
		}
	}
	
 	// Task 1-i: Command to change the current default directory
	if (strcmp(command, "cd") == 0 || strcmp(command, "cd\n") == 0){
		
		if(strlen(args[0]) <=0){
			printf("PWD: %s\n", getcwd(cwd, sizeof(cwd)));
		}
		
		//Checks to see whether or not the directory exists. If the directory exists, change directory
		else {
			if(chdir(args[0])< 0){
				fputs("Cannot find directory\n", stderr);
			}
			else{
				chdir(args[0]);
				printf("Directory: %s\n", getcwd(cwd, sizeof(cwd)));
			}
		}
	}

    // Task 1-ii: Clears the screen
    else if(strcmp(command, "clr") == 0 || strcmp(command, "clr\n") == 0){
      clear();
    }

    // Task 1-iii: List the contents of directory
    else if(strcmp(command, "dir") == 0 || strcmp(command, "dir\n") == 0){
		//Lists arguments associated with the directory
		DIR *d;
		struct dirent *dir;
		
		//Opens up the directory
		d = opendir(args[0]);
		
		//Check if the directory has been opened
		if(d){
           //Reads items within the directory and then print the items
           while((dir = readdir(d)) != NULL){
               printf("args%s\n", dir -> d_name);
           }
           //Closes the directory
           closedir(d);
		}
	}

    // Task 1-iv: List all the environment strings
    else if(strcmp(command, "environ") == 0 || strcmp(command, "environ\n") == 0){
		listEnv();
	}

    // Task 1-v: The echo command
	else if(strcmp(command, "echo") == 0 || strcmp(command, "echo\n") == 0){
		for(int i=0; i <=numWords; i++){
			printf("%s ", args[i]);
		}
		printf("\n");
    }

    // Task 1- vi: Displays the user manual
	else if(strcmp(command, "help") == 0 || strcmp(command, "help\n") == 0){
		helpManual();
	}

    // Task 1-vii: Pauses operations of the shell until 'Enter' is pressed
	else if (strcmp(command, "pause") == 0 || strcmp(command, "pause\n") == 0){
		pauseShell();
	}

	// Task 1-viii: Quit command to exit the shell
	else if (strcmp(command, "quit") == 0 || strcmp(command, "quit\n") == 0){
		return EXIT_SUCCESS;
	}

	// If the user enters an unsupported command
	else{
		fputs("Unsupported command, use help to display the manual\n", stderr);
	}

  // Empty arrays for new inputs
	memset(command, 0, BUFFER_LEN);
	memset(args, 0, sizeof(args[BUFFER_LEN][BUFFER_LEN]));

	// Update working directory
  printf("%s$ ", getcwd(cwd, sizeof(cwd)));
  }
    
	return EXIT_SUCCESS;
}

