/**
	How to create a zombie process
	Zombie process -> when a child process terminates without notifying the parent

**/
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>



int main(){

	pid_t pid;

	pid = fork();

	if(pid<0)
		printf("Error : Operation failed\n");

	if(pid == 0){

		printf("\nChild process Pid<%d>\n",getpid());
		printf("My parent Pid<%d>\n",getppid());

	}else{

		printf("Parent process pid<%d>\n",getpid());
		printf("My child Pid<%d>\n",pid);

	}

	printf("Out");

return 0;
}
