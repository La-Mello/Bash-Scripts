/**
		Program to demonstrate Inter process communication 
			by the use of pipes

	popen -> opens a pipe stream to/ from a process
		the stream is unidirectional(works one way)

	FILE *popen(const char* command, const char *type)

	# Params
		- Process for communication
		- send/recieve data ; 'w'(writting/sending data) 'r'(reading/recieving data)

	# the first process is the running one and the other is specified in the first arg of the popen function
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

	FILE *p;

	char buf[30];

	sprintf(buf,"some words");

	p = popen("wc -c","w");//opens a process

	fwrite(buf,sizeof(char),strlen(buf),p);

	pclose(p);

return 0;
}
