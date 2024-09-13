# GET NEXT LINE 🚀

In this project we must create a function called get next line that takes a file descriptor and returns the string of the next line (until the next '/n') from where the file descriptor was before.
In a loop it must return the entire content from a file descriptor line by line. The prototype must be char *get_next_line(int fd). If must return NUll if there is nothing else to read or an error ocurred.
Also in the bonus part the function must manage multiple file descriptors at the same time (for example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd)
* Allowed functions: read, malloc, free.
* Not allowed: lseek(), global variables.

## Topics & Learnings
+ file descriptors managing
+ read and write functions
+ file permissions
+ standard input, standar output and standard error
+ buffer and buffer size managing
+ static variables
