#include<unistd.h>
#include<stdio.h>

#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

/**
Demonstration of read operation before using lseek() sys call

*/


int main(){

	int fd,n;

	char buff[30];

	fd=open("seeking",O_RDWR);

	read(fd,buff,10);
	write(1,buff,10);
printf("\n");
	read(fd,buff,10);
	write(1,buff,10);

return 0;
}
