/**

		PROGRAM TO ILLUSTRATE IPC USING NAMED PIPES

		will be using the mkfifo()

	#Headers
		<unistd.h>
		<fcntl.h>

	#syntax
		//int mkfifo(const char * pathname, mode_t mode);
		open("pipe_name",permisions);

	#returns
		a file descriptor to the pipe

	## Program that recieves data from a named pipe


	## NOTE
		Program requires a sender to execute successful otherwise it will be blocked


	## COMPILE
		gcc mkfifo_reciever.c -o receive
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

	int fd,n;

	char buf[50];

	fd=open("fifo0",O_RDONLY);//opens the pipe in read only

	n=read(fd,buf,30);//reading first 30 bytes from the pipe

	printf("Reciever Process : [%d] recieved data\n",getpid());

	write(1,buf,n);//writting data to stdout
return 0;
}
