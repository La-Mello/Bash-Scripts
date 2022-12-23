/**

		PROGRAM TO ILLUSTRATE IPC USING NAMED PIPES

		will be using the mkfifo()

	#Headers
		<unistd.h>
		<fcntl.h>

	#syntax
		//int mkfifo(const char * pathname, mode_t mode);
		open("pipe_name",permisions)

	#params
		-> pathname/name of pipe
		-> permisions or mode in integer form

	#returns
		a file descriptor to the pipe

	## Program that sends data to named pipe


	## NOTE
		Program requires a reciever to execute successful otherwise it will be blocked


	## COMPILE
		gcc mkfifo_sender.c -o sender

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

	int fd;

	fd=open("fifo0",O_WRONLY);//opens the pipe in write only

	write(fd,"Hello brian",11);

	printf("Sender Process : [%d] sent data\n",getpid());

return 0;
}
