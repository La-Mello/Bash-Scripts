/***
* A program to demonstrate the lseek system call
* Repositions read/write file offset
* used to read from a file from a specified position

* #Header files
	<sys/types.h>
	<unistd.h>

* syntax
	off_t lseek(int fd, off_t offset, int whence);

* # File descriptors[fd] are three 0,1,2
*  0-standard input device e.g. keyboard<stdin>
*  1-standard output device e.g. screen<stdout>
*  2-standard error<stderr>
*  3-File operations

*whence

	SEEK_END - position cursor at the end

offset is a negative to go behind some characters then start reading from there
since the cursor is positioned at the end

* #Returns the offset/reposition positioned

*/

#include<stdio.h>
#include <unistd.h>
//header files
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

	int n,fd,f1;
	char buff[30];

	fd=open("seeking", O_RDWR);//opens the file in read  and write

	f1=lseek(fd,-11,SEEK_END);//positions cursor at the end and come back 11 characters

	printf("Pointer at %d\n",f1);

	read(fd,buff,10);

	write(1,buff,10);

	printf("\n");

return 0;
}


