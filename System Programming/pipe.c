/***
*		 A program to demonstrate the pipe system call
*	 used to achieve inter process communication
	 allowing the output of one process to be used as the input of another process

	syntax :
		int pipe(int fd[2]);

		creates a unidirectional pipe

		writing end fd[1] sending data
		reading end fd[0] recieving data

there will be two processes
	the parent sends data to the child and the child displays the data

*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

	pid_t pid;
	int fd[2];
	char buf[100];

	pipe(fd);

	pid=fork();//creating parent and child process

	if(pid < 0)
		printf("Error : failed to create child process");

	if(pid == 0){//child process

//		sleep(2);

		printf("\nChild recieved data\n");

		int n=read(fd[0],buf,100);//reading passed value fd[0]

		write(1,buf,n);//writing to stdout


	}else{//parent process


		printf("Passing value to child\n");

		//writes data to pipe
		write(fd[1],"hello world\n",12);//sending data fd[1]

	}

return 0;
}


