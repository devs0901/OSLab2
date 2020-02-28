all: myshell
myshell: myshell.c utility.c myshell.h utility.h
gcc -Wall -std=c99 -g myshell.c utility.c -lm -o myshell
clean: rm -f myshell.h myshell 
