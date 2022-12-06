/***
* A program to demonstrate the open system call
* used to write to a file descriptor

* #Header files
	<sys/types.h>
	<sys/stat.h>
	<fcntl.h>

* syntax 
	int open(const char *pathname,int flags); --if file exists
	int open(const char *pathname,int flags,mode_t mode) --if doesnt exist

* # File descriptors[fd] are three 0,1,2
*  0-standard input device e.g. keyboard<stdin>
*  1-standard output device e.g. screen<stdout>
*  2-standard error<stderr>
*  3-File operations

* #Returns the file descriptor of the file

*/

#include<stdio.h>
#include <unistd.h>

//header files
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){

	int n,fd;
	char buff[30];

	fd=open("text.txt", O_RDONLY);//opens the file in read only
	printf("%d\n",fd);

	n=read(fd,buff,30);//reading from the file first 30 characters

	//last param is the permisions of the file
	fd=open("created.txt", O_CREAT|O_WRONLY,0642);
	//creates a new file in write only
	//either creates a file or opens it
	/*
		since O_WRONLY overwrites the existing file if exists
		we can use the switch
			O_WRONLY|O_APPEND
		to append the data
	*/

	write(1,buff,n);//outputting to stdout

	write(fd,buff,n);//writting to another file

	fd=open("text2.txt",O_WRONLY|O_APPEND);

	write(fd,buff,n);//writting to an already existing file
return 0;
}


