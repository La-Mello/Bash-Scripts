#include<stdio.h>

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

/**
	# A program to demonstrate the dup2() system call
	  used to duplicate a file descriptor to a file

	#Takes as a parameter the old file descriptor and the new file descriptor
	i.e. gives the user an option to define a file descriptor

*	#Returns the new file descriptor if process was successful or -1 otherwise

	May return errors depending on the processes >>Refer to dup2() undero dup manual<<

**/


int main(){

	int fd,fd1;

	fd=open("seeking",O_RDONLY);

	printf("Initial file descriptor : %d\n",fd);

	fd1=dup2(fd,5);//making the dup2 system call on fd and a chosed fd value of 5

	printf("Duplicated file descriptor : %d\n",fd1);

return 0;
}
