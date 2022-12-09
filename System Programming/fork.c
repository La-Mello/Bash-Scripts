/***
* A program to demonstrate the fork system call
* it is used to create/duplicate a <child> process

	# Headers
	 <sys/types.h>
	 <unistd.h>


*	# Takes no parameters

	# Returns: value of type <pid_t>

	* In success it returns the different values of pid in each processes(i.e. the existing/parent and the duplicated/child processes)

	* -1|<0 if the process was unsuccessfull
	* 0 to the child process to get the child process id use getpid()
	* >0 to the parent process or the child process id

*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){

	pid_t pid;

	pid=fork();//making the fork system call

	if(pid<0)//if there was an error
		printf("Error : Operation was unsuccessful.!!");

	if(pid == 0)//in child process
	{
		//in here we can add any code that willl be executed by the child process
//		for(int i=0;i<10;i++)
//			printf("%d+",i);
		printf("\nAm Child process with pid : %d\n",getpid());
		printf("My parent's pid is : %d\n",getppid());
	}else//in parent process
	{
		//in here we can add any code to be executed by parent only
//		for(int i=10;i>=0;i--)
//			printf("%d-",i);
		printf("\nAm a Parent  pid : %d\n",getpid());
		printf("My child PID : %d\n",pid);
	}


return 0;
}
