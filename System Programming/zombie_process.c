/**
	How to create a zombie process
	Zombie process -> when a child process terminates without notifying the parent
	parent assumes that child still exist in system while it doesn't

# run ./zombie &
# after running the ps cmd the defunct is the zombie process

#how to avoid zombie process use wait() instead of sleep()

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
		//sleep(3);//makes the parent sleep for 3 seconds to allow child to finish first
		wait(NULL); 
		sleep(3);//to allow use of ps
		printf("Parent process pid<%d>\n",getpid());
		printf("My child Pid<%d>\n",pid);

	}

	printf("Out");

return 0;
}
