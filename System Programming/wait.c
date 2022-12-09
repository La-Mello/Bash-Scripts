/***
* A program to demonstrate the wait system call
* it is used to make a process(parent) wait for the executon of another process(child)
	to terminate

	# Headers
	 <sys/types.h>
	 <sys/wait.h>

*	# Takes parameter
		int *wstatus <the status of the process> can specify NULL if not interested
	# Process status can either be:
		terminated
		stopped by a signal
		resumed by a signal

	# Returns:

*  # You cannot use wait in the child process
	if we want the child process to wait for the parent we can use the sleep(n) function
	which suspends the running of the process for a specified time n
	remove the wait from the parent process

	since the parent finishes execution  before the child we need to manually
	terminate the child process by pressing ctrl+c
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	pid_t pid;

	printf("Before fork\n");
	pid=fork();//making the fork system call

	if(pid<0)//if there was an error
		printf("Error : Operation was unsuccessful.!!");

	if(pid == 0)//in child process
	{
		sleep(3);//making the child wait for parent
		printf("\nAm Child process with pid : %d\n",getpid());
		printf("My parent's pid is : %d\n",getppid());

		//lets block the code
//		for(int i=0;;i++);
	}else//in parent process
	{
//		wait(NULL);//waiting for the child to execute first
		printf("\nAm a Parent  pid : %d\n",getpid());
		printf("My child PID : %d\n",pid);
	}

	printf("Out \n");
return 0;
}
