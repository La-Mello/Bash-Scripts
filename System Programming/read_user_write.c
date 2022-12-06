#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

/**
a program that reads from a use and saves it in a file
*/
int main(){

	char data[30];

	int fd;

	printf("\nOnly max of 30 characters allowed\n");
	int n=read(0,data,30);//reading n/30 characters from the user

	fd=open("output",O_CREAT|O_WRONLY, 0642);//creating a new file
	write(fd,data,n);//writting n characters to the file

	printf("\n>>Written successfully<<");
	printf("run <cat output>to see results");


return 0;
}
