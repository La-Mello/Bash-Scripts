/**
		Program to demonstrate Inter process communication 
			by the use of pipes

		demonstrates the read from a pipe concept

	popen -> opens a pipe stream to/ from a process
		the stream is unidirectional(works one way)

	FILE *popen(const char* command, const char *type)

	# Params
		- Process for communication
		- send/recieve data ; 'w'(writting/sending data) 'r'(reading/recieving data)

	# the first process is the running one and the other is specified in the first arg of the popen function
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

	FILE *p = popen("ls","r");//opens a process to recieve data from ls command

	char buf[30];

	fread(buf,sizeof(char),20,p);

	write(1,buf,20);
	printf("\n");
	pclose(p);

return 0;
}

