# Operating Systems Lab 2: Simple Shell Manual

## Basic Principles of I/O Redirection
- Standard Input: The stream which the program uses to read inputted data, so it will accept input as text. 
- Standard Output: The stream which the program uses to write its outputted data to. Text output from the command to the shell is delivered via the standard output stream.
- Standard Error: Standard Error is the stream that the program uses to output error dialogues. It is independent of standard output and can be redirected separately. 

## Program Environment
- The environment is a Shell environment. The shell environment will basically direct the shell executables to the directory that they were executed from. 

## Background Program Execution
- Background processes are processes that run in the background. The above shell is does not rely on any background processes, and that means it can run multiple processes without having to wait for another background process to end.

## Commands
- cd <directory>: Changes the current working directory to the directory specified in the command
- clr: Clears the screen
- dir <directory>: Lists all the content within the current working directory
- environ: Lists all the environment strings
- echo<comment>: Displays the comment specified by the echo command
- help: Displays the user manual
- pause: Pauses shell operations. The “Enter” key must be pressed to resume operations
- quit: Exits the shell 
