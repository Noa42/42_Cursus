## PIPEX 🚀
In this project we must create a program that takes four arguments as following:
$ ./pipex infile command1 command2 outfile
This must recreate the exact behave from executing the following in shell:
$ <infile command1 | command2 > outfile
So we must manage the file descriptors, create the pipe between them and execute both linux commands in order

* Allowed functions: open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid.

## Topics & Learnings
* Processes, parent and child processes and communication between them
* Processes creating and handling funtions suh as fork, dup, dup2, wait, getpid etc.
* Pipes working and managing
* Deep file descriptor managing
* Parsing
* Linux environment and access to it
* Linux commands executions
* Complex error managing
