/**

		PROGRAM TO ILLUSTRATE IPC USING NAMED PIPES

		will be using the mkfifo()

	#Headers
	<sys/types.h>
	<sys/stat.h>

	#syntax
		int mkfifo(const char * pathname, mode_t mode);

	#params
		-> pathname/name of pipe
		-> permisions or mode in integer form

	#returns
		0 if successful
		<0 if unsuccessful

	## Program that creates a named pipe


	## COMPILE
		 gcc mkfifo_create.c -o create
*/

#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/stat.h>

int main(){

	int res;

	res=mkfifo("fifo0",0777);// a pipe fifo0 is created

	printf("Pipe <%d> created\n",res);

return 0;
}
