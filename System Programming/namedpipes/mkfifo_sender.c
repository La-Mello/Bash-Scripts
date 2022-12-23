/**

		PROGRAM TO ILLUSTRATE IPC USING NAMED PIPES

		will be using the mkfifo()

	#Headers
		<unistd.h>
		<fcntl.h>

	#syntax
		open("pipe_name",permisions)

	#returns
		a file descriptor to the pipe

	## Program that sends data to named pipe


	## NOTE
		Program requires a reciever to execute successful otherwise it will be blocked

		To run in non blocking mode add the attribute O_NONBLOCK while opening pipe


	## COMPILE
		gcc mkfifo_sender.c -o sender

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

	int fd;

	//O_NON_BLOCK
	fd=open("fifo0",O_WRONLY);//opens the pipe in write only

	write(fd,"Hello brian",11);

	printf("Sender Process : [%d] sent data\n",getpid());

return 0;
}
