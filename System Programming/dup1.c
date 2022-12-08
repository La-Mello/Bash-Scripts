#include<stdio.h>

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

/**
	# A program to demonstrate the dup() system call
	  used to duplicate a file descriptor to a file

	#Takes as a parameter the old file descriptor

*	#Returns the new file descriptor if process was successful or -1 otherwise

**/


int main(){

	int fd,fd1;

	fd=open("seeking",O_RDONLY);

	printf("Initial file descriptor : %d\n",fd);

	fd1=dup(fd);//making the dup system call on fd

	printf("Duplicated file descriptor : %d\n",fd1);

return 0;
}
