/**
	a program that uses a parent and a child process to read from stdin and
	write to stdout and to another file
*/


#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(){

	int pid,n,fd;
	char buff[50],buff2[45];

	//Before fork
	printf("Starting prgram\n");

	pid=fork();//create a child process

	if(pid<0)
		printf("Error : Operation not successful\n");

	if(pid == 0){//in child process

		printf("\t>In child\n");
		n=read(0,buff,45);//reading from stdin
		strcpy(buff,buff2);//copying contents of buff to buff2
	}
	else if(pid>0){//in parent process

		wait(NULL);//waiting for child to finish execution

		printf("\t>In parent\n");

		fd=open("output2",O_CREAT|O_RDWR|O_APPEND, 0642);//opening the file

		printf("File descriptor in pid<%d> : %d\n",getpid(),fd);

		write(fd,buff2,45);

		printf("Writing to file.\n");
	}

	printf("Process Id <%d> completed \n",getpid());

return 0;

}
