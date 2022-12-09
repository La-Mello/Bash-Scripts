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

	pid_t pid,qid;

	printf("Before fork\n");
	pid=fork();//making the fork system call

	if(pid<0)//if there was an error
		printf("Error : Operation was unsuccessful.!!");

	if(pid == 0)//in child process
	{
		sleep(2);//sleeps for 2 seconds
		printf("\nAm First Child process pid :< %d>\n",getpid());
		printf("My parent's pid : <%d>\n",getppid());

	}else//in parent process
	{
		//creating another process
		qid=fork();

		if(qid == 0){//second child process
			printf("Second child process pid : <%d>\n",getpid());
			printf("My parent's pid : <%d>\n",getppid());
		}else{
			waitpid(qid,NULL,0);//waiting from process 2 first
			waitpid(pid,NULL,0);//waiting for process 1
			printf("\nAm a Parent  pid : <%d>\n",getpid());
			printf("My first child PID : <%d>\n",pid);
			printf("My second child PID : <%d>\n",qid);
		}
	}

	printf("Out \n");

return 0;
}
