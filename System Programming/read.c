/***
* A program to demonstrate the read system call
* used to read from a file descriptor
* syntax   ssize_t read(int fd,const void * buff, size_t count);
* returns the size it was able to write

* # File descriptors[fd] are three 0,1,2
*  0-standard input device e.g. keyboard<stdin>
*  1-standard output device e.g. screen<stdout>
*  2-standard error<stderr>
*  In this case we use 0

* # const void *buff
    represents where to store the data read from user

* # size_t count
    the size of the data to be read

* #Returns total number of characters read<=size of data[]
*/

#include<stdio.h>
#include <unistd.h>

int main(){

	int n;
	char data[12];

	//specifies that the program should read 12 bytes from the user
	//and store them in data
	n=read(0,data,12);

	//outputting what was wrote
	//prints first n characters from data if exists
	write(1,data,n);

return 0;
}


