/***
* A program to demonstrate the write system call
* used ti write to a file descriptor
* syntax   ssize_t write(int fd,const void * buff, size_t count);
* returns the size it was able to write

* # File descriptors[fd] are three 0,1,2
*  0-standard input device e.g. keyboard
*  1-standard output device e.g. screen
*  2-standard error

* # const void *buff
    represents the data to be written in double quotes

* # size_t count
    the size of the data to be written
* #Returns the amount of bytes it was able to write
*/

#include<stdio.h>
#include <unistd.h>

int main(){

	int n;
	n=write(1,"Hello world",5);
	printf("\nFirst call returned : %d\n",n);
	n=write(1,"Hello world",11);
	printf("\nSecond call returned :%d\n",n);

return 0;
}


