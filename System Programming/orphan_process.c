/**
	How to create a orphan process
	Orphan process -> when we create a child process using fork and the parent terminates
		before the parent hence the child is running on its own

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

		sleep(10);//allowing parent to finish first
		printf("\nChild process Pid<%d>\n",getpid());
		printf("My parent Pid<%d>\n",getppid());

	}else{
		sleep(3);//to see ooutput of ps comand
		printf("Parent process pid<%d>\n",getpid());
		printf("My child Pid<%d>\n",pid);

	}

	printf("Out");

return 0;
}
